/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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


#line 80 "./syntax.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMA = 258,
    ASSIGN = 259,
    OR = 260,
    AND = 261,
    RELOP = 262,
    PLUS = 263,
    MINUS = 264,
    STAR = 265,
    DIV = 266,
    NOT = 267,
    LP = 268,
    RP = 269,
    LB = 270,
    RB = 271,
    DOT = 272,
    LOWER_THAN_ELSE = 273,
    ELSE = 274,
    INT = 275,
    FLOAT = 276,
    ID = 277,
    SEMI = 278,
    ASSIGNOP = 279,
    TYPE = 280,
    LC = 281,
    RC = 282,
    STRUCT = 283,
    RETURN = 284,
    IF = 285,
    WHILE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./syntax.y"

    int type_int;
    float type_float;
    char* type_str;
    TreeNode* type_node;

#line 171 "./syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "ASSIGN", "OR", "AND", "RELOP",
  "PLUS", "MINUS", "STAR", "DIV", "NOT", "LP", "RP", "LB", "RB", "DOT",
  "LOWER_THAN_ELSE", "ELSE", "INT", "FLOAT", "ID", "SEMI", "ASSIGNOP",
  "TYPE", "LC", "RC", "STRUCT", "RETURN", "IF", "WHILE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -15,   -67,    -7,    91,   -67,    21,    88,   -67,   -67,
      -9,    16,   -67,   -67,   -67,    82,    94,   -67,    24,   141,
      22,    51,    56,   -67,   105,   -67,   -67,   113,    93,    42,
      73,   -67,   152,   113,   109,    96,    65,    23,   111,   -67,
     113,   133,   150,   -67,   -67,   160,   -67,   142,   119,   165,
     -67,   114,    89,    57,   -67,   -67,   -67,   -67,   -67,   -67,
     167,   -67,   -67,    28,   -67,   158,    -2,    -2,    -2,   -67,
     -67,   170,    -2,   157,   166,   -67,   153,   142,   352,   161,
     134,    60,   312,   -67,   -67,   113,   113,   -67,   -67,   279,
     187,   372,   492,   215,    -2,   317,    -2,   334,   -67,   -67,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,   162,   -67,
      -2,   -67,   -67,   -67,   -67,   -67,   452,   -67,   -67,   -67,
     -67,   299,   176,   -67,   -67,   392,   179,   235,   412,   184,
     255,   464,   475,   485,   279,   279,   187,   187,   432,   -67,
     452,    -2,   -67,   188,   188,   188,   188,   188,   188,   188,
     188,   -67,   -67,   180,   186,   193,   194,   -67,   -67,   -67,
     -67,   188,   188,   188,   188,   -67,   -67,   -67,   -67
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
      35,    30,    28,     0,    27,     0,     0,     0,     0,    86,
      87,    85,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,    62,    61,     0,     0,    33,    43,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    12,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    37,    38,    39,    36,    69,    68,    66,    65,    78,
      82,    89,     0,    46,    45,     0,     0,     0,     0,     0,
       0,    72,    71,    73,    74,    75,    76,    77,     0,    84,
      70,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    88,    48,    50,    49,    47,    56,    58,    57,
      55,     0,     0,     0,     0,    52,    54,    53,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   197,   -67,   200,     3,   -67,   -67,   -67,     5,
     -67,   143,   -67,    39,   -44,   137,   130,   -67,    29,   -67,
     -66,    66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    33,     8,    11,    12,    51,
      20,    41,    42,    75,    76,    77,    34,    35,    52,    53,
      78,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    90,    91,     7,    79,    81,    93,    66,     9,     7,
      67,    68,    19,   -25,   -25,    10,   116,    21,    69,    70,
      71,    -4,     1,    29,    57,    25,   121,    40,   125,   127,
     128,   130,    19,    99,   131,   132,   133,   134,   135,   136,
     137,   138,    22,    32,   140,    60,     2,    26,    30,     3,
      58,   -60,    32,     2,   -60,   -60,     3,    36,    85,    31,
      86,   113,   -60,   -60,   -60,    46,    40,     2,   -60,   -60,
       3,   -60,   -60,   -60,    48,   121,     2,    59,   -60,     3,
     -64,     2,   -60,   -60,     3,   -60,   -60,   114,    50,    15,
      83,    13,    56,   -60,   -60,   -60,    23,    32,     2,   -60,
     -60,     3,   -60,   -60,   -60,   -60,    38,    24,   -60,   -60,
      16,    17,    84,    45,   117,   118,   -60,   -60,   -60,    39,
      65,     2,   -60,   -60,     3,   -60,   -60,   -60,    66,    28,
       2,    67,    68,     3,    61,    43,    54,    30,    82,    69,
      70,    71,    50,    65,    27,    30,   -41,    62,    72,    73,
      74,    66,    37,    63,    67,    68,    28,    88,    94,    47,
      49,   112,    69,    70,    71,    55,    80,    96,    30,   -41,
      95,    72,    73,    74,    66,    50,    64,    67,    68,    97,
      98,    88,    28,    92,   139,    69,    70,    71,   111,    65,
     142,    30,   -41,   144,    72,    73,    74,    66,   148,   161,
      67,    68,   107,    14,   108,   162,    87,   152,    69,    70,
      71,   110,   163,   164,    30,     0,   123,    72,    73,    74,
     100,   101,   102,   103,   104,   105,   106,    44,     0,     0,
     107,     0,   108,     0,     0,     0,   145,     0,   124,   110,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   146,
     107,     0,   108,     0,     0,     0,   149,     0,     0,   110,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   150,
     107,     0,   108,     0,     0,     0,     0,     0,     0,   110,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   105,
     106,     0,     0,     0,   107,     0,   108,     0,   165,   166,
     167,   168,   141,   110,   100,   101,   102,   103,   104,   105,
     106,     0,     0,   115,   107,     0,   108,     0,   126,     0,
       0,    66,     0,   110,    67,    68,    66,     0,     0,    67,
      68,     0,    69,    70,    71,   129,     0,    69,    70,    71,
       0,     0,     0,    66,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    69,    70,    71,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,     0,   108,
       0,     0,     0,     0,     0,   109,   110,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   119,   107,     0,   108,
       0,     0,     0,     0,     0,     0,   110,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   143,   107,     0,   108,
       0,     0,     0,     0,     0,     0,   110,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   147,   107,     0,   108,
       0,     0,     0,     0,     0,     0,   110,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   151,   108,
       0,     0,     0,     0,     0,     0,   110,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,     0,   108,
     101,   102,   103,   104,   105,   106,   110,     0,     0,   107,
       0,   108,   102,   103,   104,   105,   106,     0,   110,     0,
     107,     0,   108,   103,   104,   105,   106,     0,     0,   110,
     107,    66,   108,     0,    67,    68,   120,     0,     0,   110,
       0,     0,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      66,    67,    68,     0,    48,    49,    72,     9,    23,     6,
      12,    13,     7,    22,    23,    22,    82,     1,    20,    21,
      22,     0,     1,     1,     1,     1,    92,    24,    94,    95,
      96,    97,    27,    77,   100,   101,   102,   103,   104,   105,
     106,   107,    26,     1,   110,    40,    25,    23,    26,    28,
      27,     9,     1,    25,    12,    13,    28,     1,     1,    20,
       3,     1,    20,    21,    22,    23,    63,    25,    26,    27,
      28,    29,    30,    31,     1,   141,    25,    38,    27,    28,
      23,    25,     9,    27,    28,    12,    13,    27,    23,     1,
       1,     0,    27,    20,    21,    22,    14,     1,    25,    26,
      27,    28,    29,    30,    31,     9,     1,    13,    12,    13,
      22,    23,    23,    20,    85,    86,    20,    21,    22,    14,
       1,    25,    26,    27,    28,    29,    30,    31,     9,    15,
      25,    12,    13,    28,     1,    22,    27,    26,    24,    20,
      21,    22,    23,     1,     3,    26,    27,    14,    29,    30,
      31,     9,    22,     3,    12,    13,    15,    23,     1,    29,
      30,    27,    20,    21,    22,    35,     1,     1,    26,    27,
      13,    29,    30,    31,     9,    23,    16,    12,    13,    13,
      27,    23,    15,    13,    22,    20,    21,    22,    27,     1,
      14,    26,    27,    14,    29,    30,    31,     9,    14,    19,
      12,    13,    15,     6,    17,    19,    63,   141,    20,    21,
      22,    24,    19,    19,    26,    -1,     1,    29,    30,    31,
       5,     6,     7,     8,     9,    10,    11,    27,    -1,    -1,
      15,    -1,    17,    -1,    -1,    -1,     1,    -1,    23,    24,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,     1,    -1,    -1,    24,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    10,
      11,    -1,    -1,    -1,    15,    -1,    17,    -1,   161,   162,
     163,   164,     3,    24,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,     1,    15,    -1,    17,    -1,     1,    -1,
      -1,     9,    -1,    24,    12,    13,     9,    -1,    -1,    12,
      13,    -1,    20,    21,    22,     1,    -1,    20,    21,    22,
      -1,    -1,    -1,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    23,    24,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,    17,
       6,     7,     8,     9,    10,    11,    24,    -1,    -1,    15,
      -1,    17,     7,     8,     9,    10,    11,    -1,    24,    -1,
      15,    -1,    17,     8,     9,    10,    11,    -1,    -1,    24,
      15,     9,    17,    -1,    12,    13,    14,    -1,    -1,    24,
      -1,    -1,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    25,    28,    33,    34,    35,    37,    38,    23,
      22,    39,    40,     0,    34,     1,    22,    23,    36,    41,
      42,     1,    26,    14,    13,     1,    23,     3,    15,     1,
      26,    45,     1,    37,    48,    49,     1,    48,     1,    14,
      37,    43,    44,    22,    36,    20,    23,    48,     1,    48,
      23,    41,    50,    51,    27,    48,    27,     1,    27,    45,
      41,     1,    14,     3,    16,     1,     9,    12,    13,    20,
      21,    22,    29,    30,    31,    45,    46,    47,    52,    46,
       1,    46,    24,     1,    23,     1,     3,    43,    23,    52,
      52,    52,    13,    52,     1,    13,     1,    13,    27,    46,
       5,     6,     7,     8,     9,    10,    11,    15,    17,    23,
      24,    27,    27,     1,    27,     1,    52,    50,    50,    14,
      14,    52,    53,     1,    23,    52,     1,    52,    52,     1,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    22,
      52,     3,    14,    14,    14,     1,    14,    14,    14,     1,
      14,    16,    53,    47,    47,    47,    47,    47,    47,    47,
      47,    19,    19,    19,    19,    47,    47,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 48 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Program",NULL,1,child, 0, (yyloc).first_line);
                //if (legal)
                    //print_ast($$, 0);
                Root=(yyval.type_node);
                }
#line 1642 "./syntax.tab.c"
    break;

  case 3:
#line 57 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDefList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1652 "./syntax.tab.c"
    break;

  case 4:
#line 62 "./syntax.y"
                  {
                (yyval.type_node)=create_node("ExtDefList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1659 "./syntax.tab.c"
    break;

  case 5:
#line 65 "./syntax.y"
                                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1669 "./syntax.tab.c"
    break;

  case 6:
#line 70 "./syntax.y"
                                 { yyerror("Missing \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 1675 "./syntax.tab.c"
    break;

  case 7:
#line 71 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1685 "./syntax.tab.c"
    break;

  case 8:
#line 76 "./syntax.y"
                      { yyerror("Missing \';\'", (yylsp[-1]).last_line); legal = 0; }
#line 1691 "./syntax.tab.c"
    break;

  case 9:
#line 77 "./syntax.y"
                 { yyerror("Error in declarations", (yylsp[0]).last_line); legal = 0; }
#line 1697 "./syntax.tab.c"
    break;

  case 10:
#line 78 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDef",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1707 "./syntax.tab.c"
    break;

  case 11:
#line 83 "./syntax.y"
                                  { yyerror("Error in declarations", (yylsp[-1]).first_line); legal = 0; }
#line 1713 "./syntax.tab.c"
    break;

  case 12:
#line 84 "./syntax.y"
                                                 { yyerror("Missing \'{\'", (yylsp[-5]).first_line); legal = 0; }
#line 1719 "./syntax.tab.c"
    break;

  case 13:
#line 85 "./syntax.y"
                                   { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 1725 "./syntax.tab.c"
    break;

  case 14:
#line 87 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDecList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1735 "./syntax.tab.c"
    break;

  case 15:
#line 93 "./syntax.y"
                              {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ExtDecList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1745 "./syntax.tab.c"
    break;

  case 16:
#line 102 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Specifier",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1755 "./syntax.tab.c"
    break;

  case 17:
#line 107 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Specifier",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1765 "./syntax.tab.c"
    break;

  case 18:
#line 113 "./syntax.y"
                                             {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StructSpecifier",NULL,5,child, 0, (yyloc).first_line);
                }
#line 1775 "./syntax.tab.c"
    break;

  case 19:
#line 118 "./syntax.y"
                                     { yyerror("Missing \'{\'", (yylsp[-4]).first_line); legal = 0; }
#line 1781 "./syntax.tab.c"
    break;

  case 20:
#line 119 "./syntax.y"
                                     { yyerror("Missing \'}\'", (yylsp[0]).first_line); legal = 0; }
#line 1787 "./syntax.tab.c"
    break;

  case 21:
#line 120 "./syntax.y"
                                { yyerror("Invalid struct definition", (yylsp[-1]).first_line); legal = 0; }
#line 1793 "./syntax.tab.c"
    break;

  case 22:
#line 121 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StructSpecifier",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1803 "./syntax.tab.c"
    break;

  case 23:
#line 127 "./syntax.y"
           {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("OptTag",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1813 "./syntax.tab.c"
    break;

  case 24:
#line 132 "./syntax.y"
                  { (yyval.type_node)=create_node("OptTag",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1819 "./syntax.tab.c"
    break;

  case 25:
#line 134 "./syntax.y"
        {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Tag",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1829 "./syntax.tab.c"
    break;

  case 26:
#line 143 "./syntax.y"
           {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarDec",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1839 "./syntax.tab.c"
    break;

  case 27:
#line 148 "./syntax.y"
                       {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarDec",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1849 "./syntax.tab.c"
    break;

  case 28:
#line 156 "./syntax.y"
                         {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("FunDec",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1859 "./syntax.tab.c"
    break;

  case 29:
#line 163 "./syntax.y"
               { yyerror("Invalid function declaration", (yylsp[0]).first_line); legal = 0; }
#line 1865 "./syntax.tab.c"
    break;

  case 30:
#line 164 "./syntax.y"
                          { yyerror("Missing \')\'", (yylsp[-3]).first_line); legal = 0; }
#line 1871 "./syntax.tab.c"
    break;

  case 31:
#line 165 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("FunDec",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1881 "./syntax.tab.c"
    break;

  case 32:
#line 170 "./syntax.y"
                  { yyerror("Missing \')\'", (yylsp[-2]).first_line); legal = 0; }
#line 1887 "./syntax.tab.c"
    break;

  case 33:
#line 172 "./syntax.y"
                                {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1897 "./syntax.tab.c"
    break;

  case 34:
#line 177 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("VarList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1907 "./syntax.tab.c"
    break;

  case 35:
#line 183 "./syntax.y"
                           {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("ParamDec",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1917 "./syntax.tab.c"
    break;

  case 36:
#line 192 "./syntax.y"
                               {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("CompSt",NULL,4,child, 0, (yyloc).first_line);
                }
#line 1927 "./syntax.tab.c"
    break;

  case 37:
#line 198 "./syntax.y"
                           { yyerror("Invalid definitions", (yylsp[-2]).first_line); legal = 0; }
#line 1933 "./syntax.tab.c"
    break;

  case 38:
#line 199 "./syntax.y"
                          { yyerror("Invalid statements", (yylsp[-1]).first_line); legal = 0; }
#line 1939 "./syntax.tab.c"
    break;

  case 39:
#line 200 "./syntax.y"
                                { yyerror("Missing \'}\'", (yylsp[0]).first_line); legal = 0; }
#line 1945 "./syntax.tab.c"
    break;

  case 40:
#line 202 "./syntax.y"
                        {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("StmtList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1955 "./syntax.tab.c"
    break;

  case 41:
#line 207 "./syntax.y"
                  { (yyval.type_node)=create_node("StmtList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 1961 "./syntax.tab.c"
    break;

  case 42:
#line 209 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,2,child, 0, (yyloc).first_line);
                }
#line 1971 "./syntax.tab.c"
    break;

  case 43:
#line 214 "./syntax.y"
                 { yyerror("Error in expressions", (yylsp[0]).first_line); legal = 0; }
#line 1977 "./syntax.tab.c"
    break;

  case 44:
#line 218 "./syntax.y"
             {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,1,child, 0, (yyloc).first_line);
                }
#line 1987 "./syntax.tab.c"
    break;

  case 45:
#line 223 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,3,child, 0, (yyloc).first_line);
                }
#line 1997 "./syntax.tab.c"
    break;

  case 46:
#line 228 "./syntax.y"
                       { yyerror("Missing \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 2003 "./syntax.tab.c"
    break;

  case 47:
#line 229 "./syntax.y"
                                              {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,5,child, 0, (yyloc).first_line);
                }
#line 2013 "./syntax.tab.c"
    break;

  case 48:
#line 234 "./syntax.y"
                           { yyerror("Missing \'(\'", (yylsp[-4]).first_line); legal = 0; }
#line 2019 "./syntax.tab.c"
    break;

  case 49:
#line 235 "./syntax.y"
                            { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 2025 "./syntax.tab.c"
    break;

  case 50:
#line 236 "./syntax.y"
                          { yyerror("Error in condition", (yylsp[-4]).first_line); legal = 0; }
#line 2031 "./syntax.tab.c"
    break;

  case 51:
#line 237 "./syntax.y"
                                  {
                TreeNode** child=(TreeNode**)malloc(7*sizeof(TreeNode*));
                child[0]=(yyvsp[-6].type_node);child[1]=(yyvsp[-5].type_node);child[2]=(yyvsp[-4].type_node);child[3]=(yyvsp[-3].type_node);child[4]=(yyvsp[-2].type_node);child[5]=(yyvsp[-1].type_node);child[6]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,7,child, 0, (yyloc).first_line);
                }
#line 2041 "./syntax.tab.c"
    break;

  case 52:
#line 242 "./syntax.y"
                                     { yyerror("Missing \'(\'", (yylsp[-6]).first_line); legal = 0; }
#line 2047 "./syntax.tab.c"
    break;

  case 53:
#line 243 "./syntax.y"
                                     { yyerror("Missing \')\'", (yylsp[-6]).first_line); legal = 0; }
#line 2053 "./syntax.tab.c"
    break;

  case 54:
#line 244 "./syntax.y"
                                    { yyerror("Missing \';\' or \',\'", (yylsp[-6]).first_line); legal = 0; }
#line 2059 "./syntax.tab.c"
    break;

  case 55:
#line 245 "./syntax.y"
                           {
                TreeNode** child=(TreeNode**)malloc(5*sizeof(TreeNode*));
                child[0]=(yyvsp[-4].type_node);child[1]=(yyvsp[-3].type_node);child[2]=(yyvsp[-2].type_node);child[3]=(yyvsp[-1].type_node);child[4]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Stmt",NULL,5,child, 0, (yyloc).first_line);
                }
#line 2069 "./syntax.tab.c"
    break;

  case 56:
#line 250 "./syntax.y"
                              { yyerror("Missing \'(\'", (yylsp[-4]).first_line); legal = 0; }
#line 2075 "./syntax.tab.c"
    break;

  case 57:
#line 251 "./syntax.y"
                              { yyerror("Missing \')\'", (yylsp[-4]).first_line); legal = 0; }
#line 2081 "./syntax.tab.c"
    break;

  case 58:
#line 252 "./syntax.y"
                             { yyerror("Error in condition", (yylsp[-4]).first_line); legal = 0; }
#line 2087 "./syntax.tab.c"
    break;

  case 59:
#line 257 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DefList",NULL,2,child, 0, (yyloc).first_line);
                }
#line 2097 "./syntax.tab.c"
    break;

  case 60:
#line 262 "./syntax.y"
                  { (yyval.type_node)=create_node("DefList",NULL,0,NULL, 0, (yyloc).first_line); }
#line 2103 "./syntax.tab.c"
    break;

  case 61:
#line 264 "./syntax.y"
                            {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Def",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2113 "./syntax.tab.c"
    break;

  case 62:
#line 269 "./syntax.y"
                              { yyerror("Missing \';\' or \',\'", (yylsp[-2]).first_line); legal = 0; }
#line 2119 "./syntax.tab.c"
    break;

  case 63:
#line 271 "./syntax.y"
                  { yyerror("Error in declarations", (yylsp[-1]).first_line); legal = 0; }
#line 2125 "./syntax.tab.c"
    break;

  case 64:
#line 273 "./syntax.y"
             {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DecList",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2135 "./syntax.tab.c"
    break;

  case 65:
#line 278 "./syntax.y"
                        {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("DecList",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2145 "./syntax.tab.c"
    break;

  case 66:
#line 283 "./syntax.y"
                        { yyerror("Missing \',\' or \';\'", (yylsp[-2]).first_line); legal = 0; }
#line 2151 "./syntax.tab.c"
    break;

  case 67:
#line 285 "./syntax.y"
            {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Dec",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2161 "./syntax.tab.c"
    break;

  case 68:
#line 290 "./syntax.y"
                          {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Dec",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2171 "./syntax.tab.c"
    break;

  case 69:
#line 295 "./syntax.y"
                            { yyerror("Expect expression", (yylsp[-2]).first_line); legal = 0; }
#line 2177 "./syntax.tab.c"
    break;

  case 70:
#line 300 "./syntax.y"
                      {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2187 "./syntax.tab.c"
    break;

  case 71:
#line 306 "./syntax.y"
                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2197 "./syntax.tab.c"
    break;

  case 72:
#line 312 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2207 "./syntax.tab.c"
    break;

  case 73:
#line 318 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2217 "./syntax.tab.c"
    break;

  case 74:
#line 324 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2227 "./syntax.tab.c"
    break;

  case 75:
#line 330 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2237 "./syntax.tab.c"
    break;

  case 76:
#line 336 "./syntax.y"
                   {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2247 "./syntax.tab.c"
    break;

  case 77:
#line 342 "./syntax.y"
                  {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2257 "./syntax.tab.c"
    break;

  case 78:
#line 348 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2267 "./syntax.tab.c"
    break;

  case 79:
#line 354 "./syntax.y"
                {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,2,child, 0, (yyloc).first_line);
                }
#line 2277 "./syntax.tab.c"
    break;

  case 80:
#line 360 "./syntax.y"
              {
                TreeNode** child=(TreeNode**)malloc(2*sizeof(TreeNode*));
                child[0]=(yyvsp[-1].type_node);child[1]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,2,child, 0, (yyloc).first_line);
                }
#line 2287 "./syntax.tab.c"
    break;

  case 81:
#line 366 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,4,child, 0, (yyloc).first_line);
                }
#line 2297 "./syntax.tab.c"
    break;

  case 82:
#line 371 "./syntax.y"
               {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2307 "./syntax.tab.c"
    break;

  case 83:
#line 379 "./syntax.y"
                    {
                TreeNode** child=(TreeNode**)malloc(4*sizeof(TreeNode*));
                child[0]=(yyvsp[-3].type_node);child[1]=(yyvsp[-2].type_node);child[2]=(yyvsp[-1].type_node);child[3]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,4,child, 0, (yyloc).first_line);
                }
#line 2317 "./syntax.tab.c"
    break;

  case 84:
#line 386 "./syntax.y"
                 {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2327 "./syntax.tab.c"
    break;

  case 85:
#line 392 "./syntax.y"
         {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2337 "./syntax.tab.c"
    break;

  case 86:
#line 397 "./syntax.y"
          {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2347 "./syntax.tab.c"
    break;

  case 87:
#line 402 "./syntax.y"
            {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Exp",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2357 "./syntax.tab.c"
    break;

  case 88:
#line 408 "./syntax.y"
                     {
                TreeNode** child=(TreeNode**)malloc(3*sizeof(TreeNode*));
                child[0]=(yyvsp[-2].type_node);child[1]=(yyvsp[-1].type_node);child[2]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Args",NULL,3,child, 0, (yyloc).first_line);
                }
#line 2367 "./syntax.tab.c"
    break;

  case 89:
#line 413 "./syntax.y"
          {
                TreeNode** child=(TreeNode**)malloc(sizeof(TreeNode*));
                child[0]=(yyvsp[0].type_node);
                (yyval.type_node)=create_node("Args",NULL,1,child, 0, (yyloc).first_line);
                }
#line 2377 "./syntax.tab.c"
    break;


#line 2381 "./syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 419 "./syntax.y"

#include "lex.yy.c"

yyerror(const char* s, int line) {
    if (strcmp(s, "syntax error") != 0)
        printf("Error type B at Line %d: %s\n", line, s);
}
