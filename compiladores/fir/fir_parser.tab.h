/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FIR_PARSER_TAB_H_INCLUDED
# define YY_YY_FIR_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tWHILE = 258,                  /* tWHILE  */
    tIF = 259,                     /* tIF  */
    tWRITE = 260,                  /* tWRITE  */
    tWRITELN = 261,                /* tWRITELN  */
    tAT = 262,                     /* tAT  */
    tSHIFT = 263,                  /* tSHIFT  */
    tFINALLY = 264,                /* tFINALLY  */
    tDO = 265,                     /* tDO  */
    tLEAVE = 266,                  /* tLEAVE  */
    tRESTART = 267,                /* tRESTART  */
    tRETURN = 268,                 /* tRETURN  */
    tSIZEOF = 269,                 /* tSIZEOF  */
    tLOGAND = 270,                 /* tLOGAND  */
    tLOGNOT = 271,                 /* tLOGNOT  */
    tLOGOR = 272,                  /* tLOGOR  */
    tTHEN = 273,                   /* tTHEN  */
    tEXTERNAL = 274,               /* tEXTERNAL  */
    tPRIVATE = 275,                /* tPRIVATE  */
    tRTVALUE = 276,                /* tRTVALUE  */
    tPUBLIC = 277,                 /* tPUBLIC  */
    tTYPE_INT = 278,               /* tTYPE_INT  */
    tTYPE_STRING = 279,            /* tTYPE_STRING  */
    tTYPE_FLOAT = 280,             /* tTYPE_FLOAT  */
    tTYPE_VOID = 281,              /* tTYPE_VOID  */
    tINTEGER = 282,                /* tINTEGER  */
    tFLOAT = 283,                  /* tFLOAT  */
    tIDENTIFIER = 284,             /* tIDENTIFIER  */
    tSTRING = 285,                 /* tSTRING  */
    tNULLPTR = 286,                /* tNULLPTR  */
    tELSE = 287,                   /* tELSE  */
    tCOMMA = 288,                  /* tCOMMA  */
    tCBRACKL = 289,                /* tCBRACKL  */
    tCBRACKR = 290,                /* tCBRACKR  */
    tBRACKL = 291,                 /* tBRACKL  */
    tBRACKR = 292,                 /* tBRACKR  */
    tEQ = 293,                     /* tEQ  */
    tNE = 294,                     /* tNE  */
    tGE = 295,                     /* tGE  */
    tLE = 296,                     /* tLE  */
    tUNARY = 297                   /* tUNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "fir_parser.y"

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
  

#line 127 "fir_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_FIR_PARSER_TAB_H_INCLUDED  */
