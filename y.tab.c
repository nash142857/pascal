/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LP = 258,
     RP = 259,
     LB = 260,
     RB = 261,
     DOT = 262,
     COMMA = 263,
     COLON = 264,
     MUL = 265,
     DIV = 266,
     PLUS = 267,
     MINUS = 268,
     ID = 269,
     GE = 270,
     GT = 271,
     LE = 272,
     LT = 273,
     EQUAL = 274,
     ASSIGN = 275,
     INTEGER = 276,
     REAL = 277,
     CHAR = 278,
     STRING = 279,
     CONST = 280,
     SEMI = 281,
     VAR = 282,
     PROGRAM = 283,
     TYPE = 284,
     SYS_TYPE = 285,
     RECORD = 286,
     DF = 287,
     ARRAY = 288,
     BP = 289,
     END = 290,
     BEGINN = 291,
     MOD = 292,
     UNEQUAL = 293,
     DR = 294,
     NOT = 295,
     AND = 296
   };
#endif
/* Tokens.  */
#define LP 258
#define RP 259
#define LB 260
#define RB 261
#define DOT 262
#define COMMA 263
#define COLON 264
#define MUL 265
#define DIV 266
#define PLUS 267
#define MINUS 268
#define ID 269
#define GE 270
#define GT 271
#define LE 272
#define LT 273
#define EQUAL 274
#define ASSIGN 275
#define INTEGER 276
#define REAL 277
#define CHAR 278
#define STRING 279
#define CONST 280
#define SEMI 281
#define VAR 282
#define PROGRAM 283
#define TYPE 284
#define SYS_TYPE 285
#define RECORD 286
#define DF 287
#define ARRAY 288
#define BP 289
#define END 290
#define BEGINN 291
#define MOD 292
#define UNEQUAL 293
#define DR 294
#define NOT 295
#define AND 296




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

	void yyerror(char * s);
	extern int yylex();
	#include "const_record.h"
	#include "type_record.h"
	#include "var_record.h"
	#include "stmt.h"
	#include "expr.h"
	#include "type_value.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>	
	#include "common.h"
	vector <base_stmt *> vt;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "parse.y"
{
	char * _str;
	int _int;
	double _double;
	base_type * _type;
	char _char;
	key_value_tuple * _tuple;
	vector <string> * _vt;
	vector < pair <string, type_ptr> > * _field;
	base_expr * _expr;
	base_stmt * _stmt;
}
/* Line 193 of yacc.c.  */
#line 207 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    18,    21,    22,    28,
      33,    35,    37,    39,    41,    44,    45,    49,    51,    54,
      56,    61,    63,    65,    67,    74,    78,    81,    83,    88,
      90,    94,    99,   105,   112,   115,   116,   119,   121,   126,
     130,   134,   138,   142,   146,   150,   154,   156,   160,   164,
     166,   170,   174,   178,   182,   184,   186,   191,   195,   198,
     201,   206,   210,   212,   214,   218,   220,   224,   227,   231,
     233,   235,   239,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    45,     7,    -1,    28,    14,    26,
      -1,    46,    63,    -1,    47,    50,    60,    -1,    25,    48,
      -1,    -1,    48,    14,    19,    49,    26,    -1,    14,    19,
      49,    26,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    29,    52,    -1,    -1,    51,     9,    14,    -1,    14,
      -1,    52,    53,    -1,    53,    -1,    14,    19,    54,    26,
      -1,    59,    -1,    55,    -1,    56,    -1,    33,     5,    59,
       6,    32,    54,    -1,    31,    57,    35,    -1,    57,    58,
      -1,    58,    -1,    51,     8,    54,    26,    -1,    30,    -1,
       3,    51,     4,    -1,    49,     7,     7,    49,    -1,    13,
      49,     7,     7,    49,    -1,    13,    49,     7,     7,    13,
      49,    -1,    27,    61,    -1,    -1,    61,    62,    -1,    62,
      -1,    51,     8,    54,    26,    -1,    36,    69,    35,    -1,
      64,    15,    65,    -1,    64,    16,    65,    -1,    64,    17,
      65,    -1,    64,    18,    65,    -1,    64,    19,    65,    -1,
      64,    38,    65,    -1,    65,    -1,    65,    12,    66,    -1,
      65,    13,    66,    -1,    66,    -1,    66,    10,    67,    -1,
      66,    11,    67,    -1,    66,    37,    67,    -1,    66,    41,
      67,    -1,    67,    -1,    14,    -1,    14,     3,    68,     4,
      -1,     3,    64,     4,    -1,    40,    67,    -1,    13,    67,
      -1,    14,     5,    64,     6,    -1,    14,     7,    14,    -1,
      21,    -1,    22,    -1,    68,     8,    64,    -1,    64,    -1,
      69,    70,    26,    -1,    70,    26,    -1,    21,     9,    71,
      -1,    71,    -1,    72,    -1,    14,    20,    64,    -1,    14,
       5,    64,     6,    20,    64,    -1,    14,     7,    14,    20,
      64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    57,    58,    61,    65,    67,    72,
      78,    86,    94,   102,   111,   112,   114,   118,   123,   124,
     126,   131,   134,   137,   141,   147,   152,   159,   163,   172,
     190,   199,   206,   219,   243,   244,   246,   247,   249,   259,
     262,   269,   276,   283,   290,   297,   304,   309,   316,   323,
     328,   335,   342,   349,   356,   361,   362,   363,   364,   370,
     376,   379,   386,   393,   401,   402,   407,   410,   415,   416,
     420,   424,   430,   437
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "MUL", "DIV", "PLUS", "MINUS", "ID", "GE", "GT", "LE", "LT",
  "EQUAL", "ASSIGN", "INTEGER", "REAL", "CHAR", "STRING", "CONST", "SEMI",
  "VAR", "PROGRAM", "TYPE", "SYS_TYPE", "RECORD", "DF", "ARRAY", "BP",
  "END", "BEGINN", "MOD", "UNEQUAL", "DR", "NOT", "AND", "$accept",
  "program", "program_head", "routine", "routine_head", "const_part",
  "const_expr_list", "const_value", "type_part", "name_list",
  "type_decl_list", "type_definition", "type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "simple_type_decl",
  "var_part", "var_decl_list", "var_decl", "routine_body", "expression",
  "expr", "term", "factor", "arg_list", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    47,    47,    48,    48,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    54,    54,    54,    55,    56,    57,    57,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    63,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     3,     2,     0,     5,     4,
       1,     1,     1,     1,     2,     0,     3,     1,     2,     1,
       4,     1,     1,     1,     6,     3,     2,     1,     4,     1,
       3,     4,     5,     6,     2,     0,     2,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     3,     2,     2,
       4,     3,     1,     1,     3,     1,     3,     2,     3,     1,
       1,     3,     6,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    15,
       3,     0,     6,     2,     0,     4,     0,    35,     0,     0,
       0,     0,     0,     0,    69,    70,     0,    14,    19,     0,
       5,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,    39,     0,    67,     0,    18,    17,     0,    34,    37,
       9,     0,     0,     0,    55,    62,    63,     0,     0,    46,
      49,    54,     0,    71,    68,    66,     0,     0,    29,     0,
       0,     0,     0,    22,    23,    21,     0,     0,    36,     8,
       0,    59,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    20,     0,    16,
      57,    65,     0,     0,    61,     0,    40,    41,    42,    43,
      44,    45,    47,    48,    50,    51,    52,    53,    73,    30,
       0,     0,    25,    26,     0,     0,    38,    56,     0,    60,
      72,     0,     0,     0,    31,    64,     0,    32,    28,     0,
      33,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    12,    71,    17,    47,
      27,    28,    72,    73,    74,   103,   104,    75,    30,    48,
      49,    15,    58,    59,    60,    61,   112,    22,    23,    24,
      25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -75
static const yytype_int16 yypact[] =
{
     -21,    -1,    21,     1,    12,   -75,    34,    67,    20,    61,
     -75,    74,    88,   -75,    25,   -75,   105,    94,   103,   112,
      78,   123,    70,   107,   -75,   -75,   116,   105,   -75,   120,
     -75,   -75,   -75,   -75,   -75,   110,   103,     2,   124,     2,
     125,   -75,   111,   -75,    73,   -75,   -75,    50,   120,   -75,
     -75,   114,     2,     2,   115,   -75,   -75,     2,    49,    76,
       0,   -75,   122,    63,   -75,   -75,   120,   103,   -75,   120,
     136,   137,   117,   -75,   -75,   -75,    73,   131,   -75,   -75,
      16,   -75,     2,     2,   132,   -75,   127,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      13,   141,   121,   -10,   -75,     6,   142,   -75,   126,   -75,
     -75,    63,    39,    54,   -75,     2,    76,    76,    76,    76,
      76,    76,     0,     0,   -75,   -75,   -75,   -75,    63,   -75,
     143,    73,   -75,   -75,   145,   103,   -75,   -75,     2,   -75,
      63,    86,   128,   129,   -75,    63,   103,   -75,   -75,    73,
     -75,   -75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -18,   -75,   -63,
     -75,   130,   -74,   -75,   -75,   -75,    52,    48,   -75,   -75,
     108,   -75,   -38,    24,   -31,   -45,   -75,   -75,   138,   118,
     -75
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    63,   108,   100,    46,    52,   102,     1,    81,    66,
      95,    96,    85,     4,    80,    53,    54,   129,    51,    67,
     110,     5,    77,    55,    56,   132,     6,    31,    32,    33,
      34,    87,    88,    89,    90,    91,    68,    97,    10,    20,
     102,    98,    57,   137,   111,   113,    21,   138,    11,   101,
     124,   125,   126,   127,    92,    86,    14,   142,    76,    77,
     139,   128,   122,   123,    87,    88,    89,    90,    91,    87,
      88,    89,    90,    91,    13,   151,    66,   140,    87,    88,
      89,    90,    91,    37,    20,    38,    67,    92,    93,    94,
      16,    21,    92,    18,    31,    32,    33,    34,    39,   146,
     145,    92,    19,    68,    69,    41,    70,    31,    32,    33,
      34,   116,   117,   118,   119,   120,   121,   144,    82,    26,
      83,    29,    84,   147,    31,    32,    33,    34,   150,   131,
      77,    36,    40,    43,    46,    44,    50,    65,    62,    20,
      79,   105,    99,   107,   106,   109,   114,   115,   130,   135,
     141,   143,   136,   134,   148,   133,    78,    45,    64,     0,
      42,   149
};

static const yytype_int16 yycheck[] =
{
      18,    39,    76,    66,    14,     3,    69,    28,    53,     3,
      10,    11,    57,    14,    52,    13,    14,     4,    36,    13,
       4,     0,     9,    21,    22,    35,    25,    21,    22,    23,
      24,    15,    16,    17,    18,    19,    30,    37,    26,    14,
     103,    41,    40,     4,    82,    83,    21,     8,    14,    67,
      95,    96,    97,    98,    38,     6,    36,   131,     8,     9,
       6,    99,    93,    94,    15,    16,    17,    18,    19,    15,
      16,    17,    18,    19,     7,   149,     3,   115,    15,    16,
      17,    18,    19,     5,    14,     7,    13,    38,    12,    13,
      29,    21,    38,    19,    21,    22,    23,    24,    20,    13,
     138,    38,    14,    30,    31,    35,    33,    21,    22,    23,
      24,    87,    88,    89,    90,    91,    92,   135,     3,    14,
       5,    27,     7,   141,    21,    22,    23,    24,   146,     8,
       9,    19,     9,    26,    14,    19,    26,    26,    14,    14,
      26,     5,    20,    26,     7,    14,    14,    20,     7,     7,
       7,     6,    26,   105,    26,   103,    48,    27,    40,    -1,
      22,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    43,    44,    14,     0,    25,    45,    46,    47,
      26,    14,    48,     7,    36,    63,    29,    50,    19,    14,
      14,    21,    69,    70,    71,    72,    14,    52,    53,    27,
      60,    21,    22,    23,    24,    49,    19,     5,     7,    20,
       9,    35,    70,    26,    19,    53,    14,    51,    61,    62,
      26,    49,     3,    13,    14,    21,    22,    40,    64,    65,
      66,    67,    14,    64,    71,    26,     3,    13,    30,    31,
      33,    49,    54,    55,    56,    59,     8,     9,    62,    26,
      64,    67,     3,     5,     7,    67,     6,    15,    16,    17,
      18,    19,    38,    12,    13,    10,    11,    37,    41,    20,
      51,    49,    51,    57,    58,     5,     7,    26,    54,    14,
       4,    64,    68,    64,    14,    20,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    67,    64,     4,
       7,     8,    35,    58,    59,     7,    26,     4,     8,     6,
      64,     7,    54,     6,    49,    64,    13,    49,    26,    32,
      49,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 62 "parse.y"
    {
			const_record::singleton() -> debug();
		}
    break;

  case 8:
#line 67 "parse.y"
    {
		auto c_r = const_record::singleton();
		vector <string> tmp;
		c_r -> insert((yyvsp[(2) - (5)]._str), (yyvsp[(4) - (5)]._tuple) -> first, tmp, (yyvsp[(4) - (5)]._tuple) -> second);
	}
    break;

  case 9:
#line 72 "parse.y"
    {
		auto c_r = const_record::singleton();
		vector <string> tmp;
		c_r -> insert((yyvsp[(1) - (4)]._str), (yyvsp[(3) - (4)]._tuple) -> first, tmp, (yyvsp[(3) - (4)]._tuple) -> second);
	}
    break;

  case 10:
#line 78 "parse.y"
    {
		value_set value;
		value._int = (yyvsp[(1) - (1)]._int);
		type_ptr ptr(new base_type(INT_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
}
    break;

  case 11:
#line 86 "parse.y"
    {
		value_set value;
		value._double = (yyvsp[(1) - (1)]._double);
		type_ptr ptr(new base_type(REAL_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 12:
#line 94 "parse.y"
    {
		value_set value;
		value._char = (yyvsp[(1) - (1)]._char);
		type_ptr ptr(new base_type(CHAR_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 13:
#line 102 "parse.y"
    {
		value_set value;
		value._str = (yyvsp[(1) - (1)]._str);
		type_ptr ptr(new base_type(STR_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 16:
#line 114 "parse.y"
    {
		(yyvsp[(1) - (3)]._vt) -> push_back((yyvsp[(3) - (3)]._str));
		(yyval._vt) = (yyvsp[(1) - (3)]._vt);
	}
    break;

  case 17:
#line 118 "parse.y"
    {
		(yyval._vt) = new vector <string> ();
		(yyval._vt) -> push_back((yyvsp[(1) - (1)]._str));
	}
    break;

  case 20:
#line 126 "parse.y"
    {
		shared_ptr <base_type> tmp((yyvsp[(3) - (4)]._type));
		type_record::single() -> insert((yyvsp[(1) - (4)]._str), tmp);	
	}
    break;

  case 21:
#line 131 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 22:
#line 134 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 23:
#line 137 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 24:
#line 141 "parse.y"
    {
		(yyval._type) = new arr_type();
		((arr_type * )(yyval._type)) -> nxt.reset((yyvsp[(6) - (6)]._type));
		((arr_type * )(yyval._type)) -> index.reset((yyvsp[(3) - (6)]._type));
	}
    break;

  case 25:
#line 147 "parse.y"
    {
		(yyval._type) = new record_type();
		((record_type * )(yyval._type)) -> vt = *(yyvsp[(2) - (3)]._field);
	}
    break;

  case 26:
#line 152 "parse.y"
    {
		for(auto i = (yyvsp[(2) - (2)]._field) -> begin(); i != (yyvsp[(2) - (2)]._field) -> end(); ++i){
			(yyvsp[(1) - (2)]._field) -> push_back(*i);
		}
		delete (yyvsp[(2) - (2)]._field);
		(yyval._field) = (yyvsp[(1) - (2)]._field);
	}
    break;

  case 27:
#line 159 "parse.y"
    {
		(yyval._field) = (yyvsp[(1) - (1)]._field);
	}
    break;

  case 28:
#line 163 "parse.y"
    {
		(yyval._field) = new vector < pair <string, type_ptr> >();
		for(auto i = (yyvsp[(1) - (4)]._vt) -> begin(); i != (yyvsp[(1) - (4)]._vt) -> end(); ++i){
			type_ptr tmp((yyvsp[(3) - (4)]._type));
			(yyval._field) -> push_back(make_pair(*i, tmp));
		}
	}
    break;

  case 29:
#line 173 "parse.y"
    {
		if(strcmp((yyvsp[(1) - (1)]._str), "int")){
			(yyval._type) = new base_type(INT_TYPE);
		}
		else
			if(strcmp((yyvsp[(1) - (1)]._str), "real")){
				(yyval._type) = new base_type(REAL_TYPE);
			}
			else
			if(strcmp((yyvsp[(1) - (1)]._str), "char")){
				(yyval._type) = new base_type(CHAR_TYPE);
			}
			else
			if(strcmp((yyvsp[(1) - (1)]._str), "string")){
				(yyval._type) = new base_type(STR_TYPE);
			}
	}
    break;

  case 30:
#line 192 "parse.y"
    {
		discrete_type * tmp = new discrete_type();
		for(auto i = (yyvsp[(2) - (3)]._vt) -> begin(); i != (yyvsp[(2) - (3)]._vt) -> end(); ++i){
			tmp -> index.push_back(*i);
		}
		(yyval._type) = tmp;
	}
    break;

  case 31:
#line 199 "parse.y"
    {
		continue_type * tmp = new continue_type();
		tmp -> left = *(yyvsp[(1) - (4)]._tuple);
		tmp -> right = *(yyvsp[(4) - (4)]._tuple);
		delete (yyvsp[(1) - (4)]._tuple);
		delete (yyvsp[(4) - (4)]._tuple);	
	}
    break;

  case 32:
#line 206 "parse.y"
    {
			if((yyvsp[(2) - (5)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(2) - (5)]._tuple) -> second._int = -(yyvsp[(2) - (5)]._tuple) -> second._int;
			}
			if((yyvsp[(2) - (5)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(2) - (5)]._tuple) -> second._double = -(yyvsp[(2) - (5)]._tuple) -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *(yyvsp[(2) - (5)]._tuple);
			tmp -> right = *(yyvsp[(5) - (5)]._tuple);
			delete (yyvsp[(5) - (5)]._tuple);
			delete (yyvsp[(2) - (5)]._tuple);
	}
    break;

  case 33:
#line 219 "parse.y"
    {
			if((yyvsp[(2) - (6)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(2) - (6)]._tuple) -> second._int = -(yyvsp[(2) - (6)]._tuple) -> second._int;
			}
			if((yyvsp[(2) - (6)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(2) - (6)]._tuple) -> second._double = -(yyvsp[(2) - (6)]._tuple) -> second._double;
			}
			if((yyvsp[(6) - (6)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(6) - (6)]._tuple) -> second._int = -(yyvsp[(6) - (6)]._tuple) -> second._int;
			}

			if((yyvsp[(6) - (6)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(6) - (6)]._tuple) -> second._double = -(yyvsp[(6) - (6)]._tuple) -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *(yyvsp[(2) - (6)]._tuple);
			tmp -> right = *(yyvsp[(6) - (6)]._tuple);
			delete (yyvsp[(2) - (6)]._tuple);
			delete (yyvsp[(6) - (6)]._tuple);
	}
    break;

  case 38:
#line 249 "parse.y"
    {
		for(auto i = (yyvsp[(1) - (4)]._vt) -> begin(); i != (yyvsp[(1) - (4)]._vt) -> end(); ++i){
			type_ptr tmp((yyvsp[(3) - (4)]._type));
			if(!var_record::single() -> insert(*i, tmp)){
				yyerror("var_decl error");
			} 
		}	
	}
    break;

  case 40:
#line 262 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = GE_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 41:
#line 269 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = GT_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 42:
#line 276 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = LE_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 43:
#line 283 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = LT_TYPE;
		(yyval._expr) = tmp;	
	}
    break;

  case 44:
#line 290 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = EQUAL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 45:
#line 297 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = UNEQUAL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 46:
#line 304 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 47:
#line 309 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = PLUS_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 48:
#line 316 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MINUS_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 49:
#line 323 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 50:
#line 328 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MUL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 51:
#line 335 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = DIV_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 52:
#line 342 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MOD_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 53:
#line 349 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = AND_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 54:
#line 356 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 58:
#line 364 "parse.y"
    {
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset((yyvsp[(2) - (2)]._expr));
		tmp -> op = NOT;
		(yyval._expr) = tmp;
	}
    break;

  case 59:
#line 370 "parse.y"
    {
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset((yyvsp[(2) - (2)]._expr));
		tmp -> op = MINUS;
		(yyval._expr) = tmp;
	}
    break;

  case 60:
#line 376 "parse.y"
    {

	}
    break;

  case 61:
#line 379 "parse.y"
    {
		record_node_value * tmp = new record_node_value();
		tmp -> id = (yyvsp[(1) - (3)]._str);
		tmp -> member = (yyvsp[(3) - (3)]._str);
		(yyval._expr) = tmp;
	}
    break;

  case 62:
#line 386 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = INT_TYPE;
		tmp -> value._int = (yyvsp[(1) - (1)]._int);
		(yyval._expr) = tmp;
	}
    break;

  case 63:
#line 393 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = REAL_TYPE;
		tmp -> value._double = (yyvsp[(1) - (1)]._double);
		(yyval._expr) = tmp;
	}
    break;

  case 66:
#line 407 "parse.y"
    {
		vt.push_back((yyvsp[(2) - (3)]._stmt));
	}
    break;

  case 67:
#line 410 "parse.y"
    {
		vt.push_back((yyvsp[(1) - (2)]._stmt));
	}
    break;

  case 68:
#line 415 "parse.y"
    {
	}
    break;

  case 69:
#line 416 "parse.y"
    {
	}
    break;

  case 70:
#line 420 "parse.y"
    {
	}
    break;

  case 71:
#line 424 "parse.y"
    {
		normal_assign * tmp = new normal_assign();	
		tmp -> value.reset((yyvsp[(3) - (3)]._expr));
		tmp -> id = (yyvsp[(1) - (3)]._str);
		(yyval._stmt) = tmp;
	}
    break;

  case 72:
#line 430 "parse.y"
    {
		arr_assign * tmp = new arr_assign();
		tmp -> id = (yyvsp[(1) - (6)]._str);
		tmp -> index.reset((yyvsp[(3) - (6)]._expr));
		tmp -> value.reset((yyvsp[(6) - (6)]._expr));
		(yyval._stmt) = tmp;
	}
    break;

  case 73:
#line 437 "parse.y"
    {
		record_assign * tmp = new record_assign();
		tmp -> id = (yyvsp[(1) - (5)]._str);
		tmp -> member = (yyvsp[(3) - (5)]._str);
		tmp -> value.reset((yyvsp[(5) - (5)]._expr));
		(yyval._stmt) = tmp;
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2087 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 445 "parse.y"

void yyerror(char * s){
	printf("%s\n", s);
	exit(0);
}
int main()
{
	printf("%d\n", yyparse());
	printf("XOR R1, R1, R1\n");
	var_record::single() -> gencode();
	for(int i = 0; i < vt.size(); ++i){
		vt[i] -> gencode();
		delete vt[i];
	}
}


 



