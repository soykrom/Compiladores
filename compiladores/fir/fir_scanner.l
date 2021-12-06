%option c++ prefix="fir_scanner_" outfile="fir_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "fir_parser.tab.h"


// output stream for building string literals
static std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}
%x X_COMMENT X_COMMENT_STR
%x X_STRING X_TIL X_IGNORE_STRING X_HEX_STR
%%
                /* Comments */

"!!".*$                /* toda a linha e ignorada */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|"\n"      ;  /* ignore everything inside the comment */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"~"                    return tLOGNOT;
"&&"                   return tLOGAND;
"||"                   return tLOGOR;

","                 return tCOMMA;
"("                 return tCBRACKL;
")"                 return tCBRACKR;
"["                 return tBRACKL;
"]"                 return tBRACKR;

"while"                return tWHILE;
"finally"			   return tFINALLY;
"do"				   return tDO;
"then"                 return tTHEN;
"if"                   return tIF; 
"else"                 return tELSE; 
"write"                return tWRITE;
"writeln"			   return tWRITELN;
"leave"				   return tLEAVE;
"restart"			   return tRESTART;
"return" 			   return tRETURN;
"unless"                 return tUNLESS;
"iterate"                return tITERATE;
"for"                    return tFOR;
"using"                  return tUSING;
"@"               	   return tAT;
">>"				   return tSHIFT;
"sizeof"			   return tSIZEOF;
"null"				   return tNULLPTR;
"->"				   return tRTVALUE;
"?"					   return tEXTERNAL;
"int"                  return tTYPE_INT;
"string"               return tTYPE_STRING;
"float"                return tTYPE_FLOAT;
"void"                 return tTYPE_VOID;

[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

<X_COMMENT_STR>"*)"\'      yy_pop_state();
<X_COMMENT_STR>"*)"        yy_pop_state(); yy_pop_state(); return tSTRING;
<X_COMMENT_STR>.|"\n"      ;  /* ignore everything inside the comment */

\'                        yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>~n              strlit << '\n';
<X_STRING>~r              strlit << '\r';
<X_STRING>~t              strlit << '\t';
<X_STRING>~~              strlit << '~';
<X_STRING>~\'             strlit << '\'';
<X_STRING>~0              yy_push_state(X_IGNORE_STRING); 
<X_STRING>~               yy_push_state(X_HEX_STR); 
<X_STRING>\'              yy_pop_state(); return tSTRING;
<X_STRING>\\\'            *yylval.s += yytext + 1;
<X_STRING>.               *yylval.s += yytext;
<X_STRING>\n              yyerror("newline in string");


<X_HEX_STR>[1-9][A-Za-z0-9] {*yylval.s = (char) strtoul(yytext, NULL, 16); yy_pop_state(); }
<X_HEX_STR>[A-Za-z0-9]   yy_pop_state();

<X_IGNORE_STRING>[A-Za-z0-9]   yy_pop_state();


[0][0-9][0-9]                   { yylval.i = strtol(yytext, nullptr, 8); return tINTEGER;} 

[1-9][0-9]*|[0]                 yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;

([1-9][0-9]*\.[0-9]+|[0-9]+\.[0-9]*|[0]\.[0-9])([eE][-+]?[0-9]+)? { yylval.d = strtod(yytext, NULL); return tFLOAT; }


[-()<>=+*/%;{}.]       return *yytext;

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
