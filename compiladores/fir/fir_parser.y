%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;  /* integer value */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  fir::block_node      *block;
  
};

%token tWHILE tIF tWRITE tWRITELN tAT tSHIFT tUNLESS tITERATE tFOR tUSING
%token tFINALLY tDO tLEAVE tRESTART tRETURN tSIZEOF tLOGAND tLOGNOT tLOGOR tTHEN
%token tEXTERNAL tPRIVATE tRTVALUE tPUBLIC
%token tTYPE_INT tTYPE_STRING tTYPE_FLOAT tTYPE_VOID

%token <i> tINTEGER
%token <d> tFLOAT
%token <s> tIDENTIFIER tSTRING
%token <expression> tNULLPTR

%type <node> stmt funcdef funcdecl arg vardec declaration leave restart
%type <sequence> declarations vardecs instrs instrs_aux vardecs_aux exprs_aux
%type <sequence> args program exprs 
%type <expression> expr var_aux literal rtval 
%type <lvalue> lval 
%type <block> block prologue epilogue
%type<type> type types void_type
%type<s> string

       

%nonassoc tIF
%nonassoc tDO
%nonassoc tTHEN
%nonassoc tELSE
%nonassoc tWHILE tFINALLY
%nonassoc tCOMMA tCBRACKL tCBRACKR tBRACKL tBRACKR

%right '='
%left tLOGOR
%left tLOGAND
%left tLOGNOT

%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right tUNARY

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

program : /* empty */                                  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
        | declarations                                 { compiler->ast($$ = $1); }
        ;

declarations : declaration                             { $$ = new cdk::sequence_node(LINE, $1);     }
             | declarations declaration                { $$ = new cdk::sequence_node(LINE, $2, $1); }
             ;

declaration : vardec ';'                               { $$ = $1; }
            | funcdecl                                 { $$ = $1; }
            | funcdef                                  { $$ = $1; }
            ;

vardec : types '*' tIDENTIFIER var_aux                 { $$ = new fir::variable_declaration_node(LINE, tPUBLIC, $1, *$3, $4); }
       | types tIDENTIFIER var_aux                     { $$ = new fir::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $3); }
       | tEXTERNAL types tIDENTIFIER                   { $$ = new fir::variable_declaration_node(LINE, tEXTERNAL, $2, *$3, nullptr); }
       ;

vardecs : vardec ';'                                   { $$ = new cdk::sequence_node(LINE, $1); }
        | vardecs vardec ';'                           { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;

vardecs_aux : /* empty */ { $$ = NULL; }
            | vardecs     { $$ = $1; }
            ;

var_aux : /* empty*/                                   { $$ = nullptr; }
        | '=' expr                                     { $$ = $2; }
        ;

funcdecl : types '*' tIDENTIFIER tCBRACKL args tCBRACKR                                               { $$ = new fir::function_decl_node(LINE, tPUBLIC, $1, *$3, $5); }
         | types tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR                                         { $$ = new fir::function_decl_node(LINE, tEXTERNAL, $1, *$3, $5); }
         | types tIDENTIFIER tCBRACKL args tCBRACKR                                                   { $$ = new fir::function_decl_node(LINE, tPRIVATE, $1, *$2, $4); }
         | void_type '*' tIDENTIFIER tCBRACKL args tCBRACKR                                           { $$ = new fir::function_decl_node(LINE, tPUBLIC, *$3, $5); }
         | void_type tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR                                     { $$ = new fir::function_decl_node(LINE, tEXTERNAL, *$3, $5); }
         | void_type tIDENTIFIER tCBRACKL args tCBRACKR                                               { $$ = new fir::function_decl_node(LINE, tPRIVATE, *$2, $4); }

         ;

funcdef : types '*' tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue                  { $$ = new fir::function_def_node(LINE, tPUBLIC, $1, *$3, $5, $7, $9, $8, $10); }
        | types tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue            { $$ = new fir::function_def_node(LINE, tEXTERNAL, $1, *$3, $5, $7, $9, $8, $10); }
        | types tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue                      { $$ = new fir::function_def_node(LINE, tPRIVATE, $1, *$2, $4, $6, $8, $7, $9); }
        | void_type '*' tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue                    { $$ = new fir::function_def_node(LINE, tPUBLIC, $1, *$3, $5, nullptr, $8, $7, $9); }
        | void_type tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue              { $$ = new fir::function_def_node(LINE, tEXTERNAL, $1, *$3, $5, nullptr, $8, $7, $9); }
        | void_type tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue                        { $$ = new fir::function_def_node(LINE, tEXTERNAL, $1, *$2, $4, nullptr, $7, $6, $8); }
        ;

prologue : /* empty */                                 { $$ = nullptr; }
         | tAT block                                   { $$ = $2; } 
         ;

epilogue : /* empty */                                 { $$ = nullptr; }
         | tSHIFT block                                { $$ = $2; }
         ;
         
block : '{' vardecs_aux instrs_aux '}'                 { $$ = new fir::block_node(LINE, $2, $3); } //CHECK CHAVETAS
      ;

rtval : /* empty */                                    { $$ = nullptr; }
      | tRTVALUE literal                               { $$ = $2; }
      ;

types : type                                           { $$ = $1; }
      | '<' types '>'                                  { $$ = cdk::reference_type::create(4, $2); }
      ;


type : tTYPE_INT                                       { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
     | tTYPE_STRING                                    { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
     | tTYPE_FLOAT                                     { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
     ;

void_type : tTYPE_VOID                                 { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
          ;
      
args : /* empty */                                     { $$ = new cdk::sequence_node(LINE); }
     | arg                                             { $$ = new cdk::sequence_node(LINE, $1); }
     | args tCOMMA arg                                 { $$ = new cdk::sequence_node(LINE, $3, $1); } 
     ;

arg : types tIDENTIFIER                                { $$ = new fir::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); delete $2; } 
    ;

instrs : stmt                                          { $$ = new cdk::sequence_node(LINE, $1); }
       | instrs stmt                                   { $$ = new cdk::sequence_node(LINE, $2, $1); }
       ;

instrs_aux : /* empty */                               { $$ = new cdk::sequence_node(LINE); }
           | instrs                                    { $$ = $1; }
           ;

leave : tLEAVE ';'                                     { $$ = new fir::leave_node(LINE); }
      | tLEAVE tINTEGER ';'                            { $$ = new fir::leave_node(LINE, $2); }
      ;

restart : tRESTART ';'                                 { $$ = new fir::restart_node(LINE); }
        | tRESTART tINTEGER ';'                        { $$ = new fir::restart_node(LINE, $2); }
        ;

stmt : expr ';'                                        { $$ = new fir::evaluation_node(LINE, $1); }
     | tWRITE exprs ';'                                { $$ = new fir::print_node(LINE, $2); }
     | tWRITELN exprs ';'                              { $$ = new fir::print_node(LINE, $2, true); }
     | tWHILE expr tDO block                           { $$ = new fir::while_node(LINE, $2, $4); }
     | tWHILE expr tDO block tFINALLY block            { $$ = new fir::while_node(LINE, $2, $4, $6); }
     | tIF expr tTHEN stmt                             { $$ = new fir::if_node(LINE, $2, $4); }
     | tIF expr tTHEN stmt tELSE stmt                  { $$ = new fir::if_else_node(LINE, $2, $4, $6); }
     | leave                                           { $$ = $1; }
     | restart                                         { $$ = $1; }
     | tRETURN                                         { $$ = new fir::return_node(LINE); }
     | tUNLESS expr tITERATE expr tFOR tINTEGER tUSING tIDENTIFIER { $$ = new fir::iterate_node(LINE, $2, $4, $6, *$8); delete $8; }
     | block                                           { $$ = $1; }
     ;

lval : tIDENTIFIER                                     { $$ = new cdk::variable_node(LINE, $1); }
     | lval tBRACKL expr tBRACKR                       { $$ = new fir::index_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
     | tCBRACKL expr tCBRACKR tBRACKL expr tBRACKR     { $$ = new fir::index_node(LINE, $2, $5); }
     ;

expr : literal                                         { $$ = $1; }
     | string                                          { $$ = new cdk::string_node(LINE, $1); }
     | lval                                            { $$ = new cdk::rvalue_node(LINE, $1); }
     | lval '=' expr                                   { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | expr '+' expr	                               { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	                               { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	                               { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	                               { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	                               { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	                               { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr tGE expr	                               { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr                                   { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	                               { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	                               { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr '>' expr	                               { $$ = new cdk::gt_node(LINE, $1, $3); }
     | tLOGNOT expr                                    { $$ = new cdk::not_node(LINE, $2); }
     | expr tLOGAND expr                               { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr tLOGOR expr                                { $$ = new cdk::or_node(LINE, $1, $3); }
     | '+' expr %prec tUNARY                           { $$ = new fir::identity_node(LINE, $2); }
     | '-' expr %prec tUNARY                           { $$ = new cdk::neg_node(LINE, $2); }
     | tIDENTIFIER tCBRACKL exprs_aux tCBRACKR         { $$ = new fir::function_call_node(LINE, *$1, $3); delete $1; }
     | tSIZEOF tCBRACKL expr tCBRACKR                  { $$ = new fir::sizeof_node(LINE, $3); }
     | tAT lval                                        { $$ = new fir::read_node(LINE); }
     | tCBRACKL expr tCBRACKR                          { $$ = $2; }
     | tBRACKL expr tBRACKR                            { $$ = new fir::alloc_node(LINE, $2); }
     | lval '?'                                        { $$ = new fir::address_of_node(LINE, $1); }
     ;

exprs : expr                                           { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs tCOMMA expr                              { $$ = new cdk::sequence_node(LINE, $3, $1); }
      ; 

exprs_aux : /* empty */                                { $$ = new cdk::sequence_node(LINE); }
          | exprs                                      { $$ = $1; }
          ;
          
string  : tSTRING                                      { $$ = $1; }
        | string tSTRING                               { $$ = $1; $$->append(*$2); delete $2; }
        ;

literal : tINTEGER                                     { $$ = new cdk::integer_node(LINE, $1); }
        | tFLOAT                                       { $$ = new cdk::double_node(LINE, $1); }
        | tNULLPTR                                     { $$ = new fir::nullptr_node(LINE); }      
        ;

%%
