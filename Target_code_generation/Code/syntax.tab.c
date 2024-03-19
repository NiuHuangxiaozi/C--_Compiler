/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
int legal = 1;
extern TreeNode* Root;


#line 81 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 4,            /* LOWER_THAN_ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_SEMI = 8,                       /* SEMI  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_RELOP = 10,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 11,                  /* ASSIGNOP  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_STAR = 14,                      /* STAR  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_DOT = 18,                       /* DOT  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_TYPE = 20,                      /* TYPE  */
  YYSYMBOL_LP = 21,                        /* LP  */
  YYSYMBOL_RP = 22,                        /* RP  */
  YYSYMBOL_LB = 23,                        /* LB  */
  YYSYMBOL_RB = 24,                        /* RB  */
  YYSYMBOL_LC = 25,                        /* LC  */
  YYSYMBOL_RC = 26,                        /* RC  */
  YYSYMBOL_STRUCT = 27,                    /* STRUCT  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 36,                /* ExtDecList  */
  YYSYMBOL_Specifier = 37,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 38,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 39,                    /* OptTag  */
  YYSYMBOL_Tag = 40,                       /* Tag  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_StmtList = 46,                  /* StmtList  */
  YYSYMBOL_Stmt = 47,                      /* Stmt  */
  YYSYMBOL_DefList = 48,                   /* DefList  */
  YYSYMBOL_Def = 49,                       /* Def  */
  YYSYMBOL_DecList = 50,                   /* DecList  */
  YYSYMBOL_Dec = 51,                       /* Dec  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    57,    62,    65,    70,    71,    76,    77,
      78,    83,    84,    85,    87,    93,   102,   107,   113,   118,
     119,   120,   121,   127,   132,   134,   143,   148,   156,   163,
     164,   165,   170,   172,   177,   183,   192,   198,   199,   200,
     202,   207,   209,   214,   218,   223,   228,   229,   234,   235,
     236,   237,   242,   243,   244,   245,   250,   251,   252,   257,
     262,   264,   269,   271,   273,   278,   283,   285,   290,   295,
     300,   306,   312,   318,   324,   330,   336,   342,   348,   354,
     360,   366,   371,   379,   386,   392,   397,   402,   408,   413
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
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN",
  "LOWER_THAN_ELSE", "INT", "FLOAT", "ID", "SEMI", "COMMA", "RELOP",
  "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT",
  "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN", "IF",
  "ELSE", "WHILE", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    -2,   -70,     7,    17,   -70,    22,   127,   -70,   -70,
       1,     6,   -70,   -70,   -70,    28,    33,   -70,    11,    -5,
      58,    20,    47,   -70,    92,   -70,   -70,    45,    60,    50,
      79,   -70,    80,    45,    64,    96,    87,    61,   114,   -70,
      45,    23,   139,   -70,   -70,    72,   -70,   136,   125,   165,
     -70,    71,   168,   151,   -70,   -70,   -70,   -70,   -70,   -70,
     122,   -70,   -70,   255,   -70,   150,   -70,   -70,   142,   312,
     312,   312,   312,    90,   119,   -70,   153,   136,   324,   159,
     110,    63,   267,   -70,   -70,    45,    45,   -70,   -70,   302,
     457,   157,   368,   198,   312,   284,   312,   293,   -70,   -70,
     -70,   312,   312,   312,   312,   312,   312,   312,   312,   180,
     312,   -70,   -70,   -70,   -70,   -70,   410,   -70,   -70,   -70,
     339,   166,   -70,   -70,   -70,   382,   170,   216,   396,   178,
     234,   451,   410,   457,   457,   157,   157,   438,   424,   -70,
     353,   312,   -70,   176,   176,   176,   176,   176,   176,   176,
     176,   -70,   -70,   172,   173,   188,   189,   -70,   -70,   -70,
     -70,   176,   176,   176,   176,   -70,   -70,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    24,     0,     2,     0,     0,    17,     9,
      23,     0,    22,     1,     3,     8,    26,     7,     0,    14,
       0,     0,     0,    29,     0,     6,     5,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,    32,    31,
       0,     0,    34,    26,    15,     0,    11,     0,     0,     0,
      63,    67,     0,     0,    19,    59,    21,    20,    18,    13,
      35,    30,    28,     0,    27,     0,    86,    87,    85,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,    62,    61,     0,     0,    33,    43,     0,
      79,    80,     0,     0,     0,     0,     0,     0,    12,    40,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    36,    69,    68,    66,    65,    82,
      89,     0,    78,    46,    45,     0,     0,     0,     0,     0,
       0,    73,    70,    74,    75,    76,    77,    71,    72,    84,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    88,    48,    50,    49,    47,    56,    58,    57,
      55,     0,     0,     0,     0,    52,    54,    53,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   192,   -70,   193,     5,   -70,   -70,   -70,     3,
     -70,   160,   -70,   109,   -33,   115,    31,   -70,    88,   -70,
     -69,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    18,    33,     8,    11,    12,    51,
      20,    41,    42,    75,    76,    77,    34,    35,    52,    53,
      78,   121
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    91,    92,    93,    27,     7,     9,    21,   -25,   -25,
      19,     7,    25,   116,    10,    79,    81,    13,    28,    26,
     120,    32,    -4,     1,    61,   125,   127,   128,   130,    40,
      19,    22,   131,   132,   133,   134,   135,   136,   137,   138,
       2,   140,     2,    60,    99,    62,   -60,     3,    36,     3,
      23,    32,    43,    37,    24,   -60,   -60,   -60,    46,    29,
      47,    49,    57,   -60,   113,    45,    55,     2,    40,   -60,
       2,   -60,   120,   -60,     3,   -60,   -60,     3,   -60,   -60,
      48,   -60,    82,    30,   -60,   -60,   -60,    58,    50,   114,
      54,    94,   -60,    38,    28,    50,    64,    32,   -60,     2,
     -60,   -60,   -60,   -60,   -60,   -60,     3,   -60,   -60,   -60,
     -60,    95,     2,    56,    39,   -60,     2,   -60,    88,     3,
      96,   -60,   -60,     3,   -60,   -60,    65,   -60,    15,    31,
      66,    67,    68,    50,    16,    17,   112,    65,    69,    30,
      97,    66,    67,    68,    70,    28,    71,    59,    63,    69,
      30,   -41,    85,    72,    73,    70,    74,    71,    88,   -64,
      86,    30,   -41,    89,    72,    73,    80,    74,   102,    83,
      66,    67,    68,   117,   118,   109,    84,    65,    69,    98,
     110,    66,    67,    68,    70,   111,    71,   139,   142,    69,
      30,   -41,   144,    72,    73,    70,    74,    71,    14,   123,
     148,    30,   161,   162,    72,    73,   124,    74,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   145,   163,   164,
      44,   110,   152,    87,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   149,     0,     0,   146,   110,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,   150,   110,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   115,     0,
       0,     0,    66,    67,    68,     2,   165,   166,   167,   168,
      69,     0,     3,     0,     0,   126,    70,     0,    71,    66,
      67,    68,     0,     0,   129,     0,     0,    69,    66,    67,
      68,     0,     0,    70,     0,    71,    69,    66,    67,    68,
       0,     0,    70,     0,    71,    69,     0,    66,    67,    68,
       0,    70,     0,    71,   119,    69,     0,     0,     0,     0,
       0,    70,   100,    71,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,   110,   141,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,   110,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,   110,   151,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
     122,   110,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   143,   110,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,   147,   110,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,   110,   101,   102,   103,   104,   105,   106,
     107,     0,   109,     0,     0,     0,     0,   110,   101,   102,
     103,   104,   105,   106,     0,     0,   109,     0,     0,     0,
       0,   110,   102,   103,   104,   105,   106,     0,   102,   109,
       0,   105,   106,     0,   110,   109,     0,     0,     0,     0,
     110
};

static const yytype_int16 yycheck[] =
{
      69,    70,    71,    72,     9,     0,     8,     1,     7,     8,
       7,     6,     1,    82,     7,    48,    49,     0,    23,     8,
      89,     1,     0,     1,     1,    94,    95,    96,    97,    24,
      27,    25,   101,   102,   103,   104,   105,   106,   107,   108,
      20,   110,    20,    40,    77,    22,    26,    27,     1,    27,
      22,     1,     7,    22,    21,     5,     6,     7,     8,     1,
      29,    30,     1,    13,     1,     5,    35,    20,    63,    19,
      20,    21,   141,    26,    27,    25,    26,    27,    28,    29,
       1,    31,    11,    25,     5,     6,     7,    26,     8,    26,
      26,     1,    13,     1,    23,     8,    24,     1,    19,    20,
      21,     5,     6,     7,    25,    26,    27,    28,    29,    13,
      31,    21,    20,    26,    22,    19,    20,    21,     8,    27,
       1,    25,    26,    27,    28,    29,     1,    31,     1,    20,
       5,     6,     7,     8,     7,     8,    26,     1,    13,    25,
      21,     5,     6,     7,    19,    23,    21,    38,     9,    13,
      25,    26,     1,    28,    29,    19,    31,    21,     8,     8,
       9,    25,    26,    21,    28,    29,     1,    31,    11,     1,
       5,     6,     7,    85,    86,    18,     8,     1,    13,    26,
      23,     5,     6,     7,    19,    26,    21,     7,    22,    13,
      25,    26,    22,    28,    29,    19,    31,    21,     6,     1,
      22,    25,    30,    30,    28,    29,     8,    31,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     1,    30,    30,
      27,    23,   141,    63,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    23,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,     7,    20,   161,   162,   163,   164,
      13,    -1,    27,    -1,    -1,     1,    19,    -1,    21,     5,
       6,     7,    -1,    -1,     1,    -1,    -1,    13,     5,     6,
       7,    -1,    -1,    19,    -1,    21,    13,     5,     6,     7,
      -1,    -1,    19,    -1,    21,    13,    -1,     5,     6,     7,
      -1,    19,    -1,    21,    22,    13,    -1,    -1,    -1,    -1,
      -1,    19,     8,    21,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    23,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    23,    11,    12,    13,    14,    15,    -1,    11,    18,
      -1,    14,    15,    -1,    23,    18,    -1,    -1,    -1,    -1,
      23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    20,    27,    33,    34,    35,    37,    38,     8,
       7,    39,    40,     0,    34,     1,     7,     8,    36,    41,
      42,     1,    25,    22,    21,     1,     8,     9,    23,     1,
      25,    45,     1,    37,    48,    49,     1,    48,     1,    22,
      37,    43,    44,     7,    36,     5,     8,    48,     1,    48,
       8,    41,    50,    51,    26,    48,    26,     1,    26,    45,
      41,     1,    22,     9,    24,     1,     5,     6,     7,    13,
      19,    21,    28,    29,    31,    45,    46,    47,    52,    46,
       1,    46,    11,     1,     8,     1,     9,    43,     8,    21,
      52,    52,    52,    52,     1,    21,     1,    21,    26,    46,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      23,    26,    26,     1,    26,     1,    52,    50,    50,    22,
      52,    53,    22,     1,     8,    52,     1,    52,    52,     1,
      52,    52,    52,    52,    52,    52,    52,    52,    52,     7,
      52,     9,    22,    22,    22,     1,    22,    22,    22,     1,
      22,    24,    53,    47,    47,    47,    47,    47,    47,    47,
      47,    30,    30,    30,    30,    47,    47,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    37,    37,    38,    38,
      38,    38,    38,    39,    39,    40,    41,    41,    42,    42,
      42,    42,    42,    43,    43,    44,    45,    45,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    49,    49,    50,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     2,     2,
       3,     4,     6,     5,     1,     3,     1,     1,     5,     5,
       5,     5,     2,     1,     0,     1,     1,     4,     4,     2,
       4,     3,     3,     3,     1,     2,     4,     4,     4,     4,
       2,     0,     2,     2,     1,     3,     3,     5,     5,     5,
       5,     7,     7,     7,     7,     5,     5,     5,     5,     2,
       0,     3,     3,     2,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 48 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Program",NULL,1,child, 0, (yyloc).first_line);
                //if (legal)
                    //print_ast($$, 0);
                Root=(yyval.type_node);
                }
#line 1411 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 57 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDefList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1421 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 62 "./syntax.y"
                  {
                (yyval.type_node)=create_node("ExtDefList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1428 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 65 "./syntax.y"
                                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1438 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier ExtDecList error  */
#line 70 "./syntax.y"
                                 { yyerror("Missing \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 1444 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier SEMI  */
#line 71 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1454 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier error  */
#line 76 "./syntax.y"
                      { yyerror("Missing \';\'", (yylsp[-1]).last_line); legal = 0; }
#line 1460 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error SEMI  */
#line 77 "./syntax.y"
                 { yyerror("Error in declarations", (yylsp[0]).last_line); legal = 0; }
#line 1466 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: Specifier FunDec CompSt  */
#line 78 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1476 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier FunDec error SEMI  */
#line 83 "./syntax.y"
                                  { yyerror("Error in declarations", (yylsp[-1]).first_line); legal = 0; }
#line 1482 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier FunDec error DefList StmtList RC  */
#line 84 "./syntax.y"
                                                 { yyerror("Missing \'{\'", (yylsp[-5]).first_line); legal = 0; }
#line 1488 "./syntax.tab.c"
    break;

  case 13: /* ExtDef: Specifier ID LP error CompSt  */
#line 85 "./syntax.y"
                                   { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 1494 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec  */
#line 87 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDecList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1504 "./syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 93 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDecList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1514 "./syntax.tab.c"
    break;

  case 16: /* Specifier: TYPE  */
#line 102 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Specifier",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1524 "./syntax.tab.c"
    break;

  case 17: /* Specifier: StructSpecifier  */
#line 107 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Specifier",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1534 "./syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 113 "./syntax.y"
                                             {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StructSpecifier",NULL,5,child, 0, (yyloc).first_line);
                }
#line 1544 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT OptTag error DefList RC  */
#line 118 "./syntax.y"
                                     { yyerror("Missing \'{\'", (yylsp[-4]).first_line); legal = 0; }
#line 1550 "./syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT OptTag LC DefList error  */
#line 119 "./syntax.y"
                                     { yyerror("Missing \'}\'", (yylsp[0]).first_line); legal = 0; }
#line 1556 "./syntax.tab.c"
    break;

  case 21: /* StructSpecifier: STRUCT OptTag LC error RC  */
#line 120 "./syntax.y"
                                { yyerror("Invalid struct definition", (yylsp[-1]).first_line); legal = 0; }
#line 1562 "./syntax.tab.c"
    break;

  case 22: /* StructSpecifier: STRUCT Tag  */
#line 121 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StructSpecifier",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1572 "./syntax.tab.c"
    break;

  case 23: /* OptTag: ID  */
#line 127 "./syntax.y"
           {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("OptTag",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1582 "./syntax.tab.c"
    break;

  case 24: /* OptTag: %empty  */
#line 132 "./syntax.y"
                  { (yyval.type_node)=create_node("OptTag",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1588 "./syntax.tab.c"
    break;

  case 25: /* Tag: ID  */
#line 134 "./syntax.y"
        {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Tag",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1598 "./syntax.tab.c"
    break;

  case 26: /* VarDec: ID  */
#line 143 "./syntax.y"
           {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarDec",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1608 "./syntax.tab.c"
    break;

  case 27: /* VarDec: VarDec LB INT RB  */
#line 148 "./syntax.y"
                       {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarDec",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1618 "./syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP VarList RP  */
#line 156 "./syntax.y"
                         {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("FunDec",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1628 "./syntax.tab.c"
    break;

  case 29: /* FunDec: error RP  */
#line 163 "./syntax.y"
               { yyerror("Invalid function declaration", (yylsp[0]).first_line); legal = 0; }
#line 1634 "./syntax.tab.c"
    break;

  case 30: /* FunDec: ID LP VarList error  */
#line 164 "./syntax.y"
                          { yyerror("Missing \')\'", (yylsp[-3]).first_line); legal = 0; }
#line 1640 "./syntax.tab.c"
    break;

  case 31: /* FunDec: ID LP RP  */
#line 165 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("FunDec",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1650 "./syntax.tab.c"
    break;

  case 32: /* FunDec: ID LP error  */
#line 170 "./syntax.y"
                  { yyerror("Missing \')\'", (yylsp[-2]).first_line); legal = 0; }
#line 1656 "./syntax.tab.c"
    break;

  case 33: /* VarList: ParamDec COMMA VarList  */
#line 172 "./syntax.y"
                                {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1666 "./syntax.tab.c"
    break;

  case 34: /* VarList: ParamDec  */
#line 177 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1676 "./syntax.tab.c"
    break;

  case 35: /* ParamDec: Specifier VarDec  */
#line 183 "./syntax.y"
                           {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ParamDec",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1686 "./syntax.tab.c"
    break;

  case 36: /* CompSt: LC DefList StmtList RC  */
#line 192 "./syntax.y"
                               {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("CompSt",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1696 "./syntax.tab.c"
    break;

  case 37: /* CompSt: LC error StmtList RC  */
#line 198 "./syntax.y"
                           { yyerror("Invalid definitions", (yylsp[-2]).first_line); legal = 0; }
#line 1702 "./syntax.tab.c"
    break;

  case 38: /* CompSt: LC DefList error RC  */
#line 199 "./syntax.y"
                          { yyerror("Invalid statements", (yylsp[-1]).first_line); legal = 0; }
#line 1708 "./syntax.tab.c"
    break;

  case 39: /* CompSt: LC DefList StmtList error  */
#line 200 "./syntax.y"
                                { yyerror("Missing \'}\'", (yylsp[0]).first_line); legal = 0; }
#line 1714 "./syntax.tab.c"
    break;

  case 40: /* StmtList: Stmt StmtList  */
#line 202 "./syntax.y"
                        {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StmtList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1724 "./syntax.tab.c"
    break;

  case 41: /* StmtList: %empty  */
#line 207 "./syntax.y"
                  { (yyval.type_node)=create_node("StmtList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1730 "./syntax.tab.c"
    break;

  case 42: /* Stmt: Exp SEMI  */
#line 209 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1740 "./syntax.tab.c"
    break;

  case 43: /* Stmt: error SEMI  */
#line 214 "./syntax.y"
                 { yyerror("Error in expressions", (yylsp[0]).first_line); legal = 0; }
#line 1746 "./syntax.tab.c"
    break;

  case 44: /* Stmt: CompSt  */
#line 218 "./syntax.y"
             {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1756 "./syntax.tab.c"
    break;

  case 45: /* Stmt: RETURN Exp SEMI  */
#line 223 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1766 "./syntax.tab.c"
    break;

  case 46: /* Stmt: RETURN Exp error  */
#line 228 "./syntax.y"
                       { yyerror("Missing \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 1772 "./syntax.tab.c"
    break;

  case 47: /* Stmt: IF LP Exp RP Stmt  */
#line 229 "./syntax.y"
                                              {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,5,child, 0, (yyloc).first_line);
                }
#line 1782 "./syntax.tab.c"
    break;

  case 48: /* Stmt: IF error Exp RP Stmt  */
#line 234 "./syntax.y"
                           { yyerror("Missing \'(\'", (yylsp[-4]).first_line); legal = 0; }
#line 1788 "./syntax.tab.c"
    break;

  case 49: /* Stmt: IF LP Exp error Stmt  */
#line 235 "./syntax.y"
                            { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 1794 "./syntax.tab.c"
    break;

  case 50: /* Stmt: IF LP error RP Stmt  */
#line 236 "./syntax.y"
                          { yyerror("Error in condition", (yylsp[-4]).first_line); legal = 0; }
#line 1800 "./syntax.tab.c"
    break;

  case 51: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 237 "./syntax.y"
                                  {
                TreeNode** child=(TreeNode**)malloc(7*sizeof(TreeNode*));
                child[0]=(yyvsp[-6].type_node);child[1]=(yyvsp[-5].type_node);child[2]=(yyvsp[-4].type_node);child[3]=(yyvsp[-3].type_node);child[4]=(yyvsp[-2].type_node);child[5]=(yyvsp[-1].type_node);child[6]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,7,child, 0, (yyloc).first_line);
                }
#line 1810 "./syntax.tab.c"
    break;

  case 52: /* Stmt: IF error Exp RP Stmt ELSE Stmt  */
#line 242 "./syntax.y"
                                     { yyerror("Missing \'(\'", (yylsp[-6]).first_line); legal = 0; }
#line 1816 "./syntax.tab.c"
    break;

  case 53: /* Stmt: IF LP Exp error Stmt ELSE Stmt  */
#line 243 "./syntax.y"
                                     { yyerror("Missing \')\'", (yylsp[-6]).first_line); legal = 0; }
#line 1822 "./syntax.tab.c"
    break;

  case 54: /* Stmt: IF LP error RP Stmt ELSE Stmt  */
#line 244 "./syntax.y"
                                    { yyerror("Missing \';\' or \',\'", (yylsp[-6]).first_line); legal = 0; }
#line 1828 "./syntax.tab.c"
    break;

  case 55: /* Stmt: WHILE LP Exp RP Stmt  */
#line 245 "./syntax.y"
                           {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,5,child, 0, (yyloc).first_line);
                }
#line 1838 "./syntax.tab.c"
    break;

  case 56: /* Stmt: WHILE error Exp RP Stmt  */
#line 250 "./syntax.y"
                              { yyerror("Missing \'(\'", (yylsp[-4]).first_line); legal = 0; }
#line 1844 "./syntax.tab.c"
    break;

  case 57: /* Stmt: WHILE LP Exp error Stmt  */
#line 251 "./syntax.y"
                              { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 1850 "./syntax.tab.c"
    break;

  case 58: /* Stmt: WHILE LP error RP Stmt  */
#line 252 "./syntax.y"
                             { yyerror("Error in condition", (yylsp[-4]).first_line); legal = 0; }
#line 1856 "./syntax.tab.c"
    break;

  case 59: /* DefList: Def DefList  */
#line 257 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DefList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1866 "./syntax.tab.c"
    break;

  case 60: /* DefList: %empty  */
#line 262 "./syntax.y"
                  { (yyval.type_node)=create_node("DefList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1872 "./syntax.tab.c"
    break;

  case 61: /* Def: Specifier DecList SEMI  */
#line 264 "./syntax.y"
                            {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Def",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1882 "./syntax.tab.c"
    break;

  case 62: /* Def: Specifier DecList error  */
#line 269 "./syntax.y"
                              { yyerror("Missing \';\' or \',\'", (yylsp[-2]).first_line); legal = 0; }
#line 1888 "./syntax.tab.c"
    break;

  case 63: /* Def: error SEMI  */
#line 271 "./syntax.y"
                  { yyerror("Error in declarations", (yylsp[-1]).first_line); legal = 0; }
#line 1894 "./syntax.tab.c"
    break;

  case 64: /* DecList: Dec  */
#line 273 "./syntax.y"
             {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DecList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1904 "./syntax.tab.c"
    break;

  case 65: /* DecList: Dec COMMA DecList  */
#line 278 "./syntax.y"
                        {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DecList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1914 "./syntax.tab.c"
    break;

  case 66: /* DecList: Dec error DecList  */
#line 283 "./syntax.y"
                        { yyerror("Missing \',\' or \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 1920 "./syntax.tab.c"
    break;

  case 67: /* Dec: VarDec  */
#line 285 "./syntax.y"
            {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Dec",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1930 "./syntax.tab.c"
    break;

  case 68: /* Dec: VarDec ASSIGNOP Exp  */
#line 290 "./syntax.y"
                          {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Dec",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1940 "./syntax.tab.c"
    break;

  case 69: /* Dec: VarDec ASSIGNOP error  */
#line 295 "./syntax.y"
                            { yyerror("Expect expression", (yylsp[-2]).first_line); legal = 0; }
#line 1946 "./syntax.tab.c"
    break;

  case 70: /* Exp: Exp ASSIGNOP Exp  */
#line 300 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1956 "./syntax.tab.c"
    break;

  case 71: /* Exp: Exp AND Exp  */
#line 306 "./syntax.y"
                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1966 "./syntax.tab.c"
    break;

  case 72: /* Exp: Exp OR Exp  */
#line 312 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1976 "./syntax.tab.c"
    break;

  case 73: /* Exp: Exp RELOP Exp  */
#line 318 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1986 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp PLUS Exp  */
#line 324 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1996 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp MINUS Exp  */
#line 330 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2006 "./syntax.tab.c"
    break;

  case 76: /* Exp: Exp STAR Exp  */
#line 336 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2016 "./syntax.tab.c"
    break;

  case 77: /* Exp: Exp DIV Exp  */
#line 342 "./syntax.y"
                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2026 "./syntax.tab.c"
    break;

  case 78: /* Exp: LP Exp RP  */
#line 348 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2036 "./syntax.tab.c"
    break;

  case 79: /* Exp: MINUS Exp  */
#line 354 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,2,child, 0, (yyloc).first_line);
                }
#line 2046 "./syntax.tab.c"
    break;

  case 80: /* Exp: NOT Exp  */
#line 360 "./syntax.y"
              {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,2,child, 0, (yyloc).first_line);
                }
#line 2056 "./syntax.tab.c"
    break;

  case 81: /* Exp: ID LP Args RP  */
#line 366 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,4,child, 0, (yyloc).first_line);
                }
#line 2066 "./syntax.tab.c"
    break;

  case 82: /* Exp: ID LP RP  */
#line 371 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2076 "./syntax.tab.c"
    break;

  case 83: /* Exp: Exp LB Exp RB  */
#line 379 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,4,child, 0, (yyloc).first_line);
                }
#line 2086 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp DOT ID  */
#line 386 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2096 "./syntax.tab.c"
    break;

  case 85: /* Exp: ID  */
#line 392 "./syntax.y"
         {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2106 "./syntax.tab.c"
    break;

  case 86: /* Exp: INT  */
#line 397 "./syntax.y"
          {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2116 "./syntax.tab.c"
    break;

  case 87: /* Exp: FLOAT  */
#line 402 "./syntax.y"
            {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2126 "./syntax.tab.c"
    break;

  case 88: /* Args: Exp COMMA Args  */
#line 408 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Args",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2136 "./syntax.tab.c"
    break;

  case 89: /* Args: Exp  */
#line 413 "./syntax.y"
          {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Args",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2146 "./syntax.tab.c"
    break;


#line 2150 "./syntax.tab.c"

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
  *++yylsp = yyloc;

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
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 419 "./syntax.y"

#include "lex.yy.c"

yyerror(const char* s, int line) {
    if (strcmp(s, "syntax error") != 0)
        printf("Error type B at Line %d: %s\n", line, s);
}
