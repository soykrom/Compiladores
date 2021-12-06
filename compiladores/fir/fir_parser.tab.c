/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "fir_parser.y"

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

#line 85 "fir_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "fir_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tWHILE = 3,                     /* tWHILE  */
  YYSYMBOL_tIF = 4,                        /* tIF  */
  YYSYMBOL_tWRITE = 5,                     /* tWRITE  */
  YYSYMBOL_tWRITELN = 6,                   /* tWRITELN  */
  YYSYMBOL_tAT = 7,                        /* tAT  */
  YYSYMBOL_tSHIFT = 8,                     /* tSHIFT  */
  YYSYMBOL_tFINALLY = 9,                   /* tFINALLY  */
  YYSYMBOL_tDO = 10,                       /* tDO  */
  YYSYMBOL_tLEAVE = 11,                    /* tLEAVE  */
  YYSYMBOL_tRESTART = 12,                  /* tRESTART  */
  YYSYMBOL_tRETURN = 13,                   /* tRETURN  */
  YYSYMBOL_tSIZEOF = 14,                   /* tSIZEOF  */
  YYSYMBOL_tLOGAND = 15,                   /* tLOGAND  */
  YYSYMBOL_tLOGNOT = 16,                   /* tLOGNOT  */
  YYSYMBOL_tLOGOR = 17,                    /* tLOGOR  */
  YYSYMBOL_tTHEN = 18,                     /* tTHEN  */
  YYSYMBOL_tEXTERNAL = 19,                 /* tEXTERNAL  */
  YYSYMBOL_tPRIVATE = 20,                  /* tPRIVATE  */
  YYSYMBOL_tRTVALUE = 21,                  /* tRTVALUE  */
  YYSYMBOL_tPUBLIC = 22,                   /* tPUBLIC  */
  YYSYMBOL_tTYPE_INT = 23,                 /* tTYPE_INT  */
  YYSYMBOL_tTYPE_STRING = 24,              /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_FLOAT = 25,               /* tTYPE_FLOAT  */
  YYSYMBOL_tTYPE_VOID = 26,                /* tTYPE_VOID  */
  YYSYMBOL_tINTEGER = 27,                  /* tINTEGER  */
  YYSYMBOL_tFLOAT = 28,                    /* tFLOAT  */
  YYSYMBOL_tIDENTIFIER = 29,               /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 30,                   /* tSTRING  */
  YYSYMBOL_tNULLPTR = 31,                  /* tNULLPTR  */
  YYSYMBOL_tELSE = 32,                     /* tELSE  */
  YYSYMBOL_tCOMMA = 33,                    /* tCOMMA  */
  YYSYMBOL_tCBRACKL = 34,                  /* tCBRACKL  */
  YYSYMBOL_tCBRACKR = 35,                  /* tCBRACKR  */
  YYSYMBOL_tBRACKL = 36,                   /* tBRACKL  */
  YYSYMBOL_tBRACKR = 37,                   /* tBRACKR  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_tEQ = 39,                       /* tEQ  */
  YYSYMBOL_tNE = 40,                       /* tNE  */
  YYSYMBOL_tGE = 41,                       /* tGE  */
  YYSYMBOL_tLE = 42,                       /* tLE  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '%'  */
  YYSYMBOL_tUNARY = 50,                    /* tUNARY  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_declarations = 57,              /* declarations  */
  YYSYMBOL_declaration = 58,               /* declaration  */
  YYSYMBOL_vardec = 59,                    /* vardec  */
  YYSYMBOL_vardecs = 60,                   /* vardecs  */
  YYSYMBOL_vardecs_aux = 61,               /* vardecs_aux  */
  YYSYMBOL_var_aux = 62,                   /* var_aux  */
  YYSYMBOL_funcdecl = 63,                  /* funcdecl  */
  YYSYMBOL_funcdef = 64,                   /* funcdef  */
  YYSYMBOL_prologue = 65,                  /* prologue  */
  YYSYMBOL_epilogue = 66,                  /* epilogue  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_rtval = 68,                     /* rtval  */
  YYSYMBOL_types = 69,                     /* types  */
  YYSYMBOL_type = 70,                      /* type  */
  YYSYMBOL_void_type = 71,                 /* void_type  */
  YYSYMBOL_args = 72,                      /* args  */
  YYSYMBOL_arg = 73,                       /* arg  */
  YYSYMBOL_instrs = 74,                    /* instrs  */
  YYSYMBOL_instrs_aux = 75,                /* instrs_aux  */
  YYSYMBOL_leave = 76,                     /* leave  */
  YYSYMBOL_restart = 77,                   /* restart  */
  YYSYMBOL_stmt = 78,                      /* stmt  */
  YYSYMBOL_lval = 79,                      /* lval  */
  YYSYMBOL_expr = 80,                      /* expr  */
  YYSYMBOL_exprs = 81,                     /* exprs  */
  YYSYMBOL_exprs_aux = 82,                 /* exprs_aux  */
  YYSYMBOL_string = 83,                    /* string  */
  YYSYMBOL_literal = 84                    /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 77 "fir_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 207 "fir_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    49,     2,     2,
       2,     2,    47,    45,     2,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      44,    38,    43,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    39,    40,    41,    42,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    83,    86,    87,    90,    91,    92,    95,
      96,    97,   100,   101,   104,   105,   108,   109,   112,   113,
     114,   115,   116,   117,   121,   122,   123,   124,   125,   126,
     129,   130,   133,   134,   137,   140,   141,   144,   145,   149,
     150,   151,   154,   157,   158,   159,   162,   165,   166,   169,
     170,   173,   174,   177,   178,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   194,   195,   196,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   227,   228,   231,   232,   235,
     236,   239,   240,   241
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tWHILE", "tIF",
  "tWRITE", "tWRITELN", "tAT", "tSHIFT", "tFINALLY", "tDO", "tLEAVE",
  "tRESTART", "tRETURN", "tSIZEOF", "tLOGAND", "tLOGNOT", "tLOGOR",
  "tTHEN", "tEXTERNAL", "tPRIVATE", "tRTVALUE", "tPUBLIC", "tTYPE_INT",
  "tTYPE_STRING", "tTYPE_FLOAT", "tTYPE_VOID", "tINTEGER", "tFLOAT",
  "tIDENTIFIER", "tSTRING", "tNULLPTR", "tELSE", "tCOMMA", "tCBRACKL",
  "tCBRACKR", "tBRACKL", "tBRACKR", "'='", "tEQ", "tNE", "tGE", "tLE",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUNARY", "';'", "'{'",
  "'}'", "'?'", "$accept", "program", "declarations", "declaration",
  "vardec", "vardecs", "vardecs_aux", "var_aux", "funcdecl", "funcdef",
  "prologue", "epilogue", "block", "rtval", "types", "type", "void_type",
  "args", "arg", "instrs", "instrs_aux", "leave", "restart", "stmt",
  "lval", "expr", "exprs", "exprs_aux", "string", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    61,   293,
     294,   295,   296,    62,    60,    43,    45,    42,    47,    37,
     297,    59,   123,   125,    63
};
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,   135,  -114,  -114,  -114,  -114,   135,    10,   131,  -114,
     -24,  -114,  -114,    -3,  -114,    -1,     4,    24,  -114,  -114,
    -114,    18,   115,    45,    53,    41,    60,  -114,  -114,    74,
     135,   167,  -114,   144,   108,   135,   118,   135,   148,   -29,
    -114,    75,   155,   167,  -114,  -114,   159,  -114,  -114,   167,
     167,   167,   167,    49,   296,   180,  -114,   135,  -114,   135,
     151,   135,   169,  -114,   135,    -2,  -114,   167,   149,   167,
     204,   167,    83,   190,  -114,  -114,   167,   167,  -114,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,  -114,   173,   176,    13,   221,    -2,  -114,    85,
     218,   225,   240,   296,   195,   206,   222,  -114,   261,   296,
     204,   331,   345,   345,    99,    99,    99,    99,    72,    72,
    -114,  -114,  -114,    -2,    13,   207,   207,    13,   218,  -114,
     207,   222,  -114,   167,  -114,   167,  -114,   218,   207,   341,
    -114,   253,   207,   207,   253,   296,   275,   207,   253,   211,
     341,    65,    55,   207,  -114,   253,   253,  -114,  -114,   253,
    -114,  -114,   212,   167,   167,   167,   167,   -13,    46,  -114,
    -114,    65,   224,  -114,  -114,  -114,   175,   255,   262,  -114,
    -114,  -114,  -114,  -114,   124,   310,    82,   110,   243,  -114,
     244,  -114,  -114,  -114,  -114,   255,   207,    65,  -114,  -114,
    -114,  -114,   287,   265,   207,    65,  -114,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    39,    40,    41,    42,     0,     0,     3,     4,
       0,     7,     8,     0,    37,     0,     0,     0,     1,     5,
       6,     0,    16,     0,     0,     0,     0,    11,    38,     0,
      43,     0,    10,    16,     0,    43,     0,    43,     0,     0,
      44,     0,     0,     0,   101,   102,    66,    99,   103,     0,
       0,     0,     0,    71,    17,    70,    69,    43,     9,    43,
       0,    43,     0,    46,     0,    20,    66,     0,    91,     0,
      84,    97,     0,     0,    87,    88,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,    23,     0,    19,    45,     0,
      30,     0,     0,    95,    98,     0,    92,    93,     0,    72,
      85,    86,    82,    81,    79,    80,    83,    78,    73,    74,
      75,    76,    77,    18,    22,     0,     0,    21,    30,    36,
       0,     0,    90,     0,    89,     0,    67,    30,     0,    14,
      31,    32,     0,     0,    32,    96,     0,     0,    32,     0,
      15,    49,     0,     0,    29,    32,    32,    26,    68,    32,
      28,    12,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    50,     0,    62,    63,    47,     0,    16,     0,    33,
      27,    25,    24,    13,     0,     0,     0,     0,     0,    51,
       0,    53,    48,    34,    55,    16,     0,     0,    56,    57,
      52,    54,    58,    60,     0,     0,    59,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   291,  -108,  -114,  -114,   -33,  -114,  -114,
     -92,    32,  -113,   -86,     1,  -114,  -114,    29,   266,  -114,
    -114,  -114,  -114,   -91,   285,   -28,    34,  -114,  -114,   230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,   150,   151,    32,    11,    12,
     126,   154,   170,   100,    38,    14,    15,    39,    40,   171,
     172,   173,   174,   175,    53,   176,   104,   105,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    13,    16,    54,    64,   -35,    65,    17,   130,    13,
      18,   128,   140,   141,   188,    70,    21,   144,    24,    99,
     125,    72,    73,    74,    75,   148,    22,    20,    25,   155,
     156,   149,   138,    27,   159,   142,   143,   137,   189,   101,
     179,   102,   162,   103,    23,   147,    26,    29,   108,   109,
     -35,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    60,   -30,    62,    28,   163,   164,
     165,   166,    41,   190,    33,    35,   167,   168,   169,    42,
     192,    43,    34,   202,   177,    76,    93,    77,    94,    36,
      96,   206,    44,    45,    46,    47,    48,   191,    79,    49,
      80,    50,   178,    78,    66,   145,   203,   146,    37,    67,
      51,    52,    44,    45,   207,   133,    48,   139,   106,    89,
      90,    91,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   198,   196,   184,   185,   103,   103,    79,
     152,    80,    59,   133,    87,    88,    89,    90,    91,    30,
       1,   152,    61,    31,     2,     3,     4,     5,     2,     3,
       4,   199,    58,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    41,     6,   157,    63,    57,     6,
     160,    42,    31,    43,    64,    76,    95,   180,   181,    69,
      79,   182,    80,    71,    44,    45,    46,    47,    48,   186,
     187,    49,    64,    50,    97,    79,    64,    80,   123,    64,
      92,   124,    51,    52,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   125,   194,   107,   133,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      79,   134,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    64,    79,   127,    80,   135,   139,
     131,   153,   161,   183,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   132,    79,   193,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      79,   195,    80,    31,   200,   201,   204,   205,   136,    19,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    79,   158,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    79,    68,    80,   197,   129,
      98,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    79,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       1,     0,     0,     0,     2,     3,     4,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     6,    83,    84,    85,    86,
      87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      33,     0,     1,    31,    33,     7,    35,     6,   100,     8,
       0,    97,   125,   126,    27,    43,    19,   130,    19,    21,
       7,    49,    50,    51,    52,   138,    29,    51,    29,   142,
     143,   139,   124,    29,   147,   127,   128,   123,    51,    67,
     153,    69,   150,    71,    47,   137,    47,    29,    76,    77,
      52,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    35,    52,    37,    43,     3,     4,
       5,     6,     7,    27,    29,    34,    11,    12,    13,    14,
     171,    16,    29,   196,    29,    36,    57,    38,    59,    29,
      61,   204,    27,    28,    29,    30,    31,    51,    15,    34,
      17,    36,    47,    54,    29,   133,   197,   135,    34,    34,
      45,    46,    27,    28,   205,    33,    31,    52,    35,    47,
      48,    49,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    51,    10,   163,   164,   165,   166,    15,
     139,    17,    34,    33,    45,    46,    47,    48,    49,    34,
      19,   150,    34,    38,    23,    24,    25,    26,    23,    24,
      25,    51,   195,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     7,    44,   144,    29,    34,    44,
     148,    14,    38,    16,    33,    36,    35,   155,   156,    34,
      15,   159,    17,    34,    27,    28,    29,    30,    31,   165,
     166,    34,    33,    36,    35,    15,    33,    17,    35,    33,
      30,    35,    45,    46,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     7,    51,    37,    33,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      15,    35,    17,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    33,    15,    35,    17,    36,    52,
      35,     8,    51,    51,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    35,    15,    53,    17,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      15,    29,    17,    38,    51,    51,     9,    32,    37,     8,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    15,    37,    17,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    15,    41,    17,    18,    99,
      64,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    15,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      19,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    44,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    23,    24,    25,    26,    44,    56,    57,    58,
      59,    63,    64,    69,    70,    71,    69,    69,     0,    58,
      51,    19,    29,    47,    19,    29,    47,    29,    43,    29,
      34,    38,    62,    29,    29,    34,    29,    34,    69,    72,
      73,     7,    14,    16,    27,    28,    29,    30,    31,    34,
      36,    45,    46,    79,    80,    83,    84,    34,    62,    34,
      72,    34,    72,    29,    33,    35,    29,    34,    79,    34,
      80,    34,    80,    80,    80,    80,    36,    38,    54,    15,
      17,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    30,    72,    72,    35,    72,    35,    73,    21,
      68,    80,    80,    80,    81,    82,    35,    37,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    35,    35,     7,    65,    35,    68,    84,
      65,    35,    35,    33,    35,    36,    37,    68,    65,    52,
      67,    67,    65,    65,    67,    80,    80,    65,    67,    59,
      60,    61,    69,     8,    66,    67,    67,    66,    37,    67,
      66,    51,    59,     3,     4,     5,     6,    11,    12,    13,
      67,    74,    75,    76,    77,    78,    80,    29,    47,    67,
      66,    66,    66,    51,    80,    80,    81,    81,    27,    51,
      27,    51,    78,    53,    51,    29,    10,    18,    51,    51,
      51,    51,    67,    78,     9,    32,    67,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    70,    71,    72,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     4,
       3,     3,     2,     3,     0,     1,     0,     2,     6,     6,
       5,     6,     6,     5,    10,    10,     9,     9,     9,     8,
       0,     2,     0,     2,     4,     0,     2,     1,     3,     1,
       1,     1,     1,     0,     1,     3,     2,     1,     2,     0,
       1,     2,     3,     2,     3,     2,     3,     3,     4,     6,
       4,     6,     1,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     2,     4,
       4,     2,     3,     3,     2,     1,     3,     0,     1,     1,
       2,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 82 "fir_parser.y"
                                                       { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1337 "fir_parser.tab.c"
    break;

  case 3: /* program: declarations  */
#line 83 "fir_parser.y"
                                                       { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1343 "fir_parser.tab.c"
    break;

  case 4: /* declarations: declaration  */
#line 86 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1349 "fir_parser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 87 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1355 "fir_parser.tab.c"
    break;

  case 6: /* declaration: vardec ';'  */
#line 90 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[-1].node); }
#line 1361 "fir_parser.tab.c"
    break;

  case 7: /* declaration: funcdecl  */
#line 91 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1367 "fir_parser.tab.c"
    break;

  case 8: /* declaration: funcdef  */
#line 92 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1373 "fir_parser.tab.c"
    break;

  case 9: /* vardec: types '*' tIDENTIFIER var_aux  */
#line 95 "fir_parser.y"
                                                       { (yyval.node) = new fir::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-3].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1379 "fir_parser.tab.c"
    break;

  case 10: /* vardec: types tIDENTIFIER var_aux  */
#line 96 "fir_parser.y"
                                                       { (yyval.node) = new fir::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1385 "fir_parser.tab.c"
    break;

  case 11: /* vardec: tEXTERNAL types tIDENTIFIER  */
#line 97 "fir_parser.y"
                                                       { (yyval.node) = new fir::variable_declaration_node(LINE, tEXTERNAL, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1391 "fir_parser.tab.c"
    break;

  case 12: /* vardecs: vardec ';'  */
#line 100 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node)); }
#line 1397 "fir_parser.tab.c"
    break;

  case 13: /* vardecs: vardecs vardec ';'  */
#line 101 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1403 "fir_parser.tab.c"
    break;

  case 14: /* vardecs_aux: %empty  */
#line 104 "fir_parser.y"
                          { (yyval.sequence) = NULL; }
#line 1409 "fir_parser.tab.c"
    break;

  case 15: /* vardecs_aux: vardecs  */
#line 105 "fir_parser.y"
                          { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1415 "fir_parser.tab.c"
    break;

  case 16: /* var_aux: %empty  */
#line 108 "fir_parser.y"
                                                       { (yyval.expression) = nullptr; }
#line 1421 "fir_parser.tab.c"
    break;

  case 17: /* var_aux: '=' expr  */
#line 109 "fir_parser.y"
                                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1427 "fir_parser.tab.c"
    break;

  case 18: /* funcdecl: types '*' tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 112 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tPUBLIC, (yyvsp[-5].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1433 "fir_parser.tab.c"
    break;

  case 19: /* funcdecl: types tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 113 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tEXTERNAL, (yyvsp[-5].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1439 "fir_parser.tab.c"
    break;

  case 20: /* funcdecl: types tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 114 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1445 "fir_parser.tab.c"
    break;

  case 21: /* funcdecl: void_type '*' tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 115 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tPUBLIC, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1451 "fir_parser.tab.c"
    break;

  case 22: /* funcdecl: void_type tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 116 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tEXTERNAL, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1457 "fir_parser.tab.c"
    break;

  case 23: /* funcdecl: void_type tIDENTIFIER tCBRACKL args tCBRACKR  */
#line 117 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_decl_node(LINE, tPRIVATE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1463 "fir_parser.tab.c"
    break;

  case 24: /* funcdef: types '*' tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue  */
#line 121 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tPUBLIC, (yyvsp[-9].type), *(yyvsp[-7].s), (yyvsp[-5].sequence), (yyvsp[-3].expression), (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1469 "fir_parser.tab.c"
    break;

  case 25: /* funcdef: types tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue  */
#line 122 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tEXTERNAL, (yyvsp[-9].type), *(yyvsp[-7].s), (yyvsp[-5].sequence), (yyvsp[-3].expression), (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1475 "fir_parser.tab.c"
    break;

  case 26: /* funcdef: types tIDENTIFIER tCBRACKL args tCBRACKR rtval prologue block epilogue  */
#line 123 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tPRIVATE, (yyvsp[-8].type), *(yyvsp[-7].s), (yyvsp[-5].sequence), (yyvsp[-3].expression), (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1481 "fir_parser.tab.c"
    break;

  case 27: /* funcdef: void_type '*' tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue  */
#line 124 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tPUBLIC, (yyvsp[-8].type), *(yyvsp[-6].s), (yyvsp[-4].sequence), nullptr, (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1487 "fir_parser.tab.c"
    break;

  case 28: /* funcdef: void_type tEXTERNAL tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue  */
#line 125 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tEXTERNAL, (yyvsp[-8].type), *(yyvsp[-6].s), (yyvsp[-4].sequence), nullptr, (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1493 "fir_parser.tab.c"
    break;

  case 29: /* funcdef: void_type tIDENTIFIER tCBRACKL args tCBRACKR prologue block epilogue  */
#line 126 "fir_parser.y"
                                                                                                      { (yyval.node) = new fir::function_def_node(LINE, tEXTERNAL, (yyvsp[-7].type), *(yyvsp[-6].s), (yyvsp[-4].sequence), nullptr, (yyvsp[-1].block), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1499 "fir_parser.tab.c"
    break;

  case 30: /* prologue: %empty  */
#line 129 "fir_parser.y"
                                                       { (yyval.block) = nullptr; }
#line 1505 "fir_parser.tab.c"
    break;

  case 31: /* prologue: tAT block  */
#line 130 "fir_parser.y"
                                                       { (yyval.block) = (yyvsp[0].block); }
#line 1511 "fir_parser.tab.c"
    break;

  case 32: /* epilogue: %empty  */
#line 133 "fir_parser.y"
                                                       { (yyval.block) = nullptr; }
#line 1517 "fir_parser.tab.c"
    break;

  case 33: /* epilogue: tSHIFT block  */
#line 134 "fir_parser.y"
                                                       { (yyval.block) = (yyvsp[0].block); }
#line 1523 "fir_parser.tab.c"
    break;

  case 34: /* block: '{' vardecs_aux instrs_aux '}'  */
#line 137 "fir_parser.y"
                                                       { (yyval.block) = new fir::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1529 "fir_parser.tab.c"
    break;

  case 35: /* rtval: %empty  */
#line 140 "fir_parser.y"
                                                       { (yyval.expression) = nullptr; }
#line 1535 "fir_parser.tab.c"
    break;

  case 36: /* rtval: tRTVALUE literal  */
#line 141 "fir_parser.y"
                                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1541 "fir_parser.tab.c"
    break;

  case 37: /* types: type  */
#line 144 "fir_parser.y"
                                                       { (yyval.type) = (yyvsp[0].type); }
#line 1547 "fir_parser.tab.c"
    break;

  case 38: /* types: '<' types '>'  */
#line 145 "fir_parser.y"
                                                       { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1553 "fir_parser.tab.c"
    break;

  case 39: /* type: tTYPE_INT  */
#line 149 "fir_parser.y"
                                                       { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1559 "fir_parser.tab.c"
    break;

  case 40: /* type: tTYPE_STRING  */
#line 150 "fir_parser.y"
                                                       { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1565 "fir_parser.tab.c"
    break;

  case 41: /* type: tTYPE_FLOAT  */
#line 151 "fir_parser.y"
                                                       { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1571 "fir_parser.tab.c"
    break;

  case 42: /* void_type: tTYPE_VOID  */
#line 154 "fir_parser.y"
                                                       { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1577 "fir_parser.tab.c"
    break;

  case 43: /* args: %empty  */
#line 157 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1583 "fir_parser.tab.c"
    break;

  case 44: /* args: arg  */
#line 158 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1589 "fir_parser.tab.c"
    break;

  case 45: /* args: args tCOMMA arg  */
#line 159 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1595 "fir_parser.tab.c"
    break;

  case 46: /* arg: types tIDENTIFIER  */
#line 162 "fir_parser.y"
                                                       { (yyval.node) = new fir::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1601 "fir_parser.tab.c"
    break;

  case 47: /* instrs: stmt  */
#line 165 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1607 "fir_parser.tab.c"
    break;

  case 48: /* instrs: instrs stmt  */
#line 166 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1613 "fir_parser.tab.c"
    break;

  case 49: /* instrs_aux: %empty  */
#line 169 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1619 "fir_parser.tab.c"
    break;

  case 50: /* instrs_aux: instrs  */
#line 170 "fir_parser.y"
                                                       { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1625 "fir_parser.tab.c"
    break;

  case 51: /* leave: tLEAVE ';'  */
#line 173 "fir_parser.y"
                                                       { (yyval.node) = new fir::leave_node(LINE); }
#line 1631 "fir_parser.tab.c"
    break;

  case 52: /* leave: tLEAVE tINTEGER ';'  */
#line 174 "fir_parser.y"
                                                       { (yyval.node) = new fir::leave_node(LINE, (yyvsp[-1].i)); }
#line 1637 "fir_parser.tab.c"
    break;

  case 53: /* restart: tRESTART ';'  */
#line 177 "fir_parser.y"
                                                       { (yyval.node) = new fir::restart_node(LINE); }
#line 1643 "fir_parser.tab.c"
    break;

  case 54: /* restart: tRESTART tINTEGER ';'  */
#line 178 "fir_parser.y"
                                                       { (yyval.node) = new fir::restart_node(LINE, (yyvsp[-1].i)); }
#line 1649 "fir_parser.tab.c"
    break;

  case 55: /* stmt: expr ';'  */
#line 181 "fir_parser.y"
                                                       { (yyval.node) = new fir::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1655 "fir_parser.tab.c"
    break;

  case 56: /* stmt: tWRITE exprs ';'  */
#line 182 "fir_parser.y"
                                                       { (yyval.node) = new fir::print_node(LINE, (yyvsp[-1].sequence)); }
#line 1661 "fir_parser.tab.c"
    break;

  case 57: /* stmt: tWRITELN exprs ';'  */
#line 183 "fir_parser.y"
                                                       { (yyval.node) = new fir::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1667 "fir_parser.tab.c"
    break;

  case 58: /* stmt: tWHILE expr tDO block  */
#line 184 "fir_parser.y"
                                                       { (yyval.node) = new fir::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1673 "fir_parser.tab.c"
    break;

  case 59: /* stmt: tWHILE expr tDO block tFINALLY block  */
#line 185 "fir_parser.y"
                                                       { (yyval.node) = new fir::while_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1679 "fir_parser.tab.c"
    break;

  case 60: /* stmt: tIF expr tTHEN stmt  */
#line 186 "fir_parser.y"
                                                       { (yyval.node) = new fir::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1685 "fir_parser.tab.c"
    break;

  case 61: /* stmt: tIF expr tTHEN stmt tELSE stmt  */
#line 187 "fir_parser.y"
                                                       { (yyval.node) = new fir::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1691 "fir_parser.tab.c"
    break;

  case 62: /* stmt: leave  */
#line 188 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1697 "fir_parser.tab.c"
    break;

  case 63: /* stmt: restart  */
#line 189 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1703 "fir_parser.tab.c"
    break;

  case 64: /* stmt: tRETURN  */
#line 190 "fir_parser.y"
                                                       { (yyval.node) = new fir::return_node(LINE); }
#line 1709 "fir_parser.tab.c"
    break;

  case 65: /* stmt: block  */
#line 191 "fir_parser.y"
                                                       { (yyval.node) = (yyvsp[0].block); }
#line 1715 "fir_parser.tab.c"
    break;

  case 66: /* lval: tIDENTIFIER  */
#line 194 "fir_parser.y"
                                                       { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1721 "fir_parser.tab.c"
    break;

  case 67: /* lval: lval tBRACKL expr tBRACKR  */
#line 195 "fir_parser.y"
                                                       { (yyval.lvalue) = new fir::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 1727 "fir_parser.tab.c"
    break;

  case 68: /* lval: tCBRACKL expr tCBRACKR tBRACKL expr tBRACKR  */
#line 196 "fir_parser.y"
                                                       { (yyval.lvalue) = new fir::index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 1733 "fir_parser.tab.c"
    break;

  case 69: /* expr: literal  */
#line 199 "fir_parser.y"
                                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1739 "fir_parser.tab.c"
    break;

  case 70: /* expr: string  */
#line 200 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1745 "fir_parser.tab.c"
    break;

  case 71: /* expr: lval  */
#line 201 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1751 "fir_parser.tab.c"
    break;

  case 72: /* expr: lval '=' expr  */
#line 202 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1757 "fir_parser.tab.c"
    break;

  case 73: /* expr: expr '+' expr  */
#line 203 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1763 "fir_parser.tab.c"
    break;

  case 74: /* expr: expr '-' expr  */
#line 204 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1769 "fir_parser.tab.c"
    break;

  case 75: /* expr: expr '*' expr  */
#line 205 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1775 "fir_parser.tab.c"
    break;

  case 76: /* expr: expr '/' expr  */
#line 206 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1781 "fir_parser.tab.c"
    break;

  case 77: /* expr: expr '%' expr  */
#line 207 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1787 "fir_parser.tab.c"
    break;

  case 78: /* expr: expr '<' expr  */
#line 208 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1793 "fir_parser.tab.c"
    break;

  case 79: /* expr: expr tGE expr  */
#line 209 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1799 "fir_parser.tab.c"
    break;

  case 80: /* expr: expr tLE expr  */
#line 210 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1805 "fir_parser.tab.c"
    break;

  case 81: /* expr: expr tNE expr  */
#line 211 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1811 "fir_parser.tab.c"
    break;

  case 82: /* expr: expr tEQ expr  */
#line 212 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1817 "fir_parser.tab.c"
    break;

  case 83: /* expr: expr '>' expr  */
#line 213 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1823 "fir_parser.tab.c"
    break;

  case 84: /* expr: tLOGNOT expr  */
#line 214 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1829 "fir_parser.tab.c"
    break;

  case 85: /* expr: expr tLOGAND expr  */
#line 215 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1835 "fir_parser.tab.c"
    break;

  case 86: /* expr: expr tLOGOR expr  */
#line 216 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1841 "fir_parser.tab.c"
    break;

  case 87: /* expr: '+' expr  */
#line 217 "fir_parser.y"
                                                       { (yyval.expression) = new fir::identity_node(LINE, (yyvsp[0].expression)); }
#line 1847 "fir_parser.tab.c"
    break;

  case 88: /* expr: '-' expr  */
#line 218 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1853 "fir_parser.tab.c"
    break;

  case 89: /* expr: tIDENTIFIER tCBRACKL exprs_aux tCBRACKR  */
#line 219 "fir_parser.y"
                                                       { (yyval.expression) = new fir::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1859 "fir_parser.tab.c"
    break;

  case 90: /* expr: tSIZEOF tCBRACKL expr tCBRACKR  */
#line 220 "fir_parser.y"
                                                       { (yyval.expression) = new fir::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1865 "fir_parser.tab.c"
    break;

  case 91: /* expr: tAT lval  */
#line 221 "fir_parser.y"
                                                       { (yyval.expression) = new fir::read_node(LINE); }
#line 1871 "fir_parser.tab.c"
    break;

  case 92: /* expr: tCBRACKL expr tCBRACKR  */
#line 222 "fir_parser.y"
                                                       { (yyval.expression) = (yyvsp[-1].expression); }
#line 1877 "fir_parser.tab.c"
    break;

  case 93: /* expr: tBRACKL expr tBRACKR  */
#line 223 "fir_parser.y"
                                                       { (yyval.expression) = new fir::alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1883 "fir_parser.tab.c"
    break;

  case 94: /* expr: lval '?'  */
#line 224 "fir_parser.y"
                                                       { (yyval.expression) = new fir::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 1889 "fir_parser.tab.c"
    break;

  case 95: /* exprs: expr  */
#line 227 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1895 "fir_parser.tab.c"
    break;

  case 96: /* exprs: exprs tCOMMA expr  */
#line 228 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1901 "fir_parser.tab.c"
    break;

  case 97: /* exprs_aux: %empty  */
#line 231 "fir_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1907 "fir_parser.tab.c"
    break;

  case 98: /* exprs_aux: exprs  */
#line 232 "fir_parser.y"
                                                       { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1913 "fir_parser.tab.c"
    break;

  case 99: /* string: tSTRING  */
#line 235 "fir_parser.y"
                                                       { (yyval.s) = (yyvsp[0].s); }
#line 1919 "fir_parser.tab.c"
    break;

  case 100: /* string: string tSTRING  */
#line 236 "fir_parser.y"
                                                       { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1925 "fir_parser.tab.c"
    break;

  case 101: /* literal: tINTEGER  */
#line 239 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 1931 "fir_parser.tab.c"
    break;

  case 102: /* literal: tFLOAT  */
#line 240 "fir_parser.y"
                                                       { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 1937 "fir_parser.tab.c"
    break;

  case 103: /* literal: tNULLPTR  */
#line 241 "fir_parser.y"
                                                       { (yyval.expression) = new fir::nullptr_node(LINE); }
#line 1943 "fir_parser.tab.c"
    break;


#line 1947 "fir_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 244 "fir_parser.y"

