/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "langage.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <vector>
  #include <string>
  #include <iostream>
  #include <stack>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);
  int temp; //Utilisé pour les boucles

  class instruction{
  public:
    instruction (const int &c, const double &v=0, const string &n="") {code = c; value = v; name = n;};  
    int code; 
    double value;     // éventuellement une valeur si besoin
    string name;      // ou une référence pour la table des données 
  };

  // Déclaration de la map qui associe
  // les noms des variables à leur valeur
  // (La table de symboles)
  map<string,double> variables;
  int ic = 0;

  // Cette map sert à stocker les adresses associées aux labels (GoTo).
  // Pour info, il est possible de faire un saut vers une étiquette
  // qui n'est pas encore déclarée (Saut vers le futur)
  // En gros, les sauts GoTo ne se font pas uniquement vers l'arrière.
  // Je vous laisse gérer les problèmes créés par le Goto :
  // - Saut vers une étiquette inexistante (ni avant, ni après)
  // - Duplication de labels (Déterminisme !!!)
  // Ne parlons pas, comme dans l'exmeple, des sauts de blocs de déclarations, 
  // ou des bloc entremêlés, ou... ou ...
  // Vous avez compris pourquoi il est banni ?
  map<string,int> adresses;

  
  // Structure pour accueillir le code généré 
  // (sone de code ou code machine ou assembleur)
  vector <instruction> code_genere;    

  // Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
  int add_instruction(const int &c, const double &v=0, const string &n="") {
      code_genere.push_back(instruction(c,v,n)); 
      ic++;
      return 0; 
   }; 



#line 125 "langage.bison.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "langage.bison.hpp".  */
#ifndef YY_YY_LANGAGE_BISON_HPP_INCLUDED
# define YY_YY_LANGAGE_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 61 "langage.y" /* yacc.c:355  */

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 163 "langage.bison.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    VAR = 259,
    PI = 260,
    SIN = 261,
    COS = 262,
    TAN = 263,
    SINH = 264,
    COSH = 265,
    TANH = 266,
    ARCSIN = 267,
    ARCCOS = 268,
    ARCTAN = 269,
    SQRT = 270,
    SI = 271,
    TANT_QUE = 272,
    FIN_TANT_QUE = 273,
    POUR = 274,
    FIN_POUR = 275,
    ALORS = 276,
    SINON = 277,
    FINSI = 278,
    SUP = 279,
    SUPEQ = 280,
    INF = 281,
    INFEQ = 282,
    ISEQ = 283,
    ISDIFF = 284,
    ABS = 285,
    MOD = 286,
    PRINT = 287,
    ASSIGN = 288,
    GOTO = 289,
    LABEL = 290,
    JMP = 291,
    JMPCOND = 292,
    POW = 293,
    FACT = 294,
    EXP = 295,
    LOG = 296,
    LN = 297,
    HASARD = 298,
    ADD = 299,
    SUB = 300,
    MULT = 301,
    DIV = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "langage.y" /* yacc.c:355  */

  double valeur;
  char nom[50];
  type_adresse adresse;  

#line 229 "langage.bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LANGAGE_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "langage.bison.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   121,   121,   122,   124,   125,   130,   131,   132,   133,
     134,   138,   143,   138,   154,   155,   157,   154,   163,   164,
     166,   163,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   204,
     205,   206,   207,   208,   209,   210
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "VAR", "PI", "SIN", "COS", "TAN",
  "SINH", "COSH", "TANH", "ARCSIN", "ARCCOS", "ARCTAN", "SQRT", "SI",
  "TANT_QUE", "FIN_TANT_QUE", "POUR", "FIN_POUR", "ALORS", "SINON",
  "FINSI", "SUP", "SUPEQ", "INF", "INFEQ", "ISEQ", "ISDIFF", "ABS", "MOD",
  "PRINT", "ASSIGN", "GOTO", "LABEL", "JMP", "JMPCOND", "POW", "FACT",
  "EXP", "LOG", "LN", "HASARD", "ADD", "SUB", "MULT", "DIV", "'\\n'",
  "':'", "'='", "'('", "')'", "$accept", "bloc", "label", "instruction",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "expr",
  "condition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    58,
      61,    40,    41
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -72,     1,   -72,   -43,   107,   -72,   -72,   -42,   -72,   -44,
     -23,   -12,    -9,    -5,     0,   156,   156,   156,    23,    25,
     -72,   -72,    26,   156,     6,   156,   170,   156,   156,    27,
     156,    -1,   -29,   156,   156,   156,   156,   156,   156,   156,
     -72,   -29,   -29,   -29,   156,   156,    28,    29,   156,   -29,
     -72,   -29,   156,   -29,   -29,   -29,   156,   195,   -72,   156,
     156,   156,   156,   156,   156,   -29,   212,   222,   232,   242,
     252,   262,   272,   191,    30,   156,   156,   282,   292,    58,
     -72,   -29,   -29,     7,     7,    12,    12,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   156,   156,   156,   156,   156,   156,
      33,    31,    32,   -72,   -72,   302,   -29,   -29,   -29,   -29,
     -29,   -29,   -72,    37,    38,   -72,    66,   -72,   -72,    59,
     -72,   -72,   -72,   -15,   -10,    -8,    88,   105,    86,   -72,
     -72,    79,   -72,    14,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     0,     6,     5,    22,    24,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
      24,    32,    33,    31,     0,     0,     0,     0,     0,     8,
      10,    42,     0,    43,    44,    45,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
      35,    41,    40,    36,    37,    38,    39,    25,    27,    29,
      26,    28,    30,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    34,     0,    50,    51,    52,    53,
      54,    55,    11,     0,     0,    48,     0,    15,    19,     0,
       2,     2,     2,     4,     4,     4,     0,     0,     0,    17,
      21,     0,     2,     4,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,     8,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    -4,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,    31,   116,   128,    46,   120,   126,    47,
     121,   127,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,     2,    59,   -16,   101,   102,     5,    34,    33,    60,
     -20,    41,    42,    43,   -12,    61,    62,    63,    64,    49,
       3,    51,    53,    54,    55,     3,    57,     3,    35,    65,
      66,    67,    68,    69,    70,    71,     3,   134,    59,    36,
      72,    50,    37,    59,    77,    60,    38,    58,    78,     3,
      60,    39,    79,    63,    64,    81,    82,    83,    84,    85,
      86,     6,    40,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    44,   105,    45,    48,    56,    75,
      76,   112,   100,   113,   114,   117,   118,   119,    22,    59,
     106,   107,   108,   109,   110,   111,    60,    25,    26,    27,
      28,    29,    61,    62,    63,    64,   129,   122,   131,    30,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   130,    21,   132,   123,   124,
     125,     0,     0,     0,     0,     0,     0,    22,     0,    23,
     133,    24,     0,     0,     0,     0,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,    30,     6,
      40,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     6,    40,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      22,     0,     0,     0,     0,     0,     0,    30,     0,    25,
      26,    27,    28,    29,     0,    94,    95,    96,    97,    98,
      99,    52,    59,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    60,     0,    61,    62,    63,    64,    61,
      62,    63,    64,    59,     0,     0,     0,    80,     0,     0,
      60,     0,     0,    59,     0,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    87,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    88,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    89,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    90,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    91,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    92,     0,    61,    62,    63,    64,
      60,     0,     0,    59,    93,     0,    61,    62,    63,    64,
      60,     0,     0,    59,   103,     0,    61,    62,    63,    64,
      60,     0,     0,     0,   104,     0,    61,    62,    63,    64,
       0,     0,     0,     0,   115
};

static const yytype_int16 yycheck[] =
{
       4,     0,    31,    18,    75,    76,    49,    51,    50,    38,
      20,    15,    16,    17,    22,    44,    45,    46,    47,    23,
      35,    25,    26,    27,    28,    35,    30,    35,    51,    33,
      34,    35,    36,    37,    38,    39,    35,    23,    31,    51,
      44,    35,    51,    31,    48,    38,    51,    48,    52,    35,
      38,    51,    56,    46,    47,    59,    60,    61,    62,    63,
      64,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    51,    79,    51,    51,    51,    51,
      51,    48,    52,    52,    52,    48,    48,    21,    30,    31,
      94,    95,    96,    97,    98,    99,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    18,    48,    22,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    20,    19,    48,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
     132,    34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    39,
      40,    41,    42,    43,    -1,    24,    25,    26,    27,    28,
      29,    51,    31,    -1,    -1,    -1,    31,    -1,    -1,    38,
      -1,    -1,    -1,    38,    -1,    44,    45,    46,    47,    44,
      45,    46,    47,    31,    -1,    -1,    -1,    52,    -1,    -1,
      38,    -1,    -1,    31,    -1,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    31,    52,    -1,    44,    45,    46,    47,
      38,    -1,    -1,    -1,    52,    -1,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,    35,    55,    49,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    19,    30,    32,    34,    39,    40,    41,    42,    43,
      51,    56,    65,    50,    51,    51,    51,    51,    51,    51,
       4,    65,    65,    65,    51,    51,    59,    62,    51,    65,
      35,    65,    51,    65,    65,    65,    51,    65,    48,    31,
      38,    44,    45,    46,    47,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    51,    51,    65,    65,    65,
      52,    65,    65,    65,    65,    65,    65,    52,    52,    52,
      52,    52,    52,    52,    24,    25,    26,    27,    28,    29,
      52,    66,    66,    52,    52,    65,    65,    65,    65,    65,
      65,    65,    48,    52,    52,    52,    57,    48,    48,    21,
      60,    63,    48,    54,    54,    54,    61,    64,    58,    18,
      20,    22,    48,    54,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    57,    58,    56,    59,    60,    61,    56,    62,    63,
      64,    56,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     0,     1,     2,     3,
       2,     0,     0,    14,     0,     0,     0,    10,     0,     0,
       0,    10,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     4,     4,     5,     1,
       3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 5:
#line 125 "langage.y" /* yacc.c:1646  */
    { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses.   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1457 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 131 "langage.y" /* yacc.c:1646  */
    {  }
#line 1463 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 132 "langage.y" /* yacc.c:1646  */
    { add_instruction(PRINT); }
#line 1469 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "langage.y" /* yacc.c:1646  */
    { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1475 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "langage.y" /* yacc.c:1646  */
    {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                              // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                              add_instruction(JMP, -999, (yyvsp[0].nom));
                           }
#line 1484 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "langage.y" /* yacc.c:1646  */
    { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JC)
                                          (yyvsp[-4].adresse).jc = ic;
                                          add_instruction(JMPCOND); }
#line 1493 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "langage.y" /* yacc.c:1646  */
    { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JMP)
                                          (yyvsp[-8].adresse).jmp = ic;
                                          add_instruction(JMP);
                                          // Je mets à jour l'adresse du saut conditionnel
                                          code_genere[(yyvsp[-8].adresse).jc].value = ic;
                                        }
#line 1505 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "langage.y" /* yacc.c:1646  */
    { // Je mets à jour l'adresse du saut inconditionnel
                                          code_genere[(yyvsp[-13].adresse).jmp].value = ic; }
#line 1512 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "langage.y" /* yacc.c:1646  */
    { (yyvsp[0].adresse).jmp = ic; }
#line 1518 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "langage.y" /* yacc.c:1646  */
    { (yyvsp[-5].adresse).jc = ic;
                                                add_instruction(JMPCOND); }
#line 1525 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "langage.y" /* yacc.c:1646  */
    { 
                                                add_instruction(JMP, (yyvsp[-7].adresse).jmp);
                                              }
#line 1533 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "langage.y" /* yacc.c:1646  */
    { 
                                                code_genere[(yyvsp[-9].adresse).jc].value = ic; 
                                              }
#line 1541 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "langage.y" /* yacc.c:1646  */
    { (yyvsp[0].adresse).jmp = ic; }
#line 1547 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 164 "langage.y" /* yacc.c:1646  */
    { (yyvsp[-5].adresse).jc = ic;
                                                add_instruction(JMPCOND); }
#line 1554 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "langage.y" /* yacc.c:1646  */
    { 
                                                add_instruction(JMP, (yyvsp[-7].adresse).jmp);
                                              }
#line 1562 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "langage.y" /* yacc.c:1646  */
    { 
                                                code_genere[(yyvsp[-9].adresse).jc].value = ic; 
                                              }
#line 1570 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 175 "langage.y" /* yacc.c:1646  */
    { add_instruction (NUM, (yyvsp[0].valeur)); }
#line 1576 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "langage.y" /* yacc.c:1646  */
    { add_instruction (NUM, 3.14159265359);}
#line 1582 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "langage.y" /* yacc.c:1646  */
    { add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1588 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "langage.y" /* yacc.c:1646  */
    { add_instruction (SIN); }
#line 1594 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 179 "langage.y" /* yacc.c:1646  */
    { add_instruction (SINH); }
#line 1600 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 180 "langage.y" /* yacc.c:1646  */
    { add_instruction (COS); }
#line 1606 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "langage.y" /* yacc.c:1646  */
    { add_instruction (COSH); }
#line 1612 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 182 "langage.y" /* yacc.c:1646  */
    { add_instruction (TAN); }
#line 1618 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 183 "langage.y" /* yacc.c:1646  */
    { add_instruction (TANH); }
#line 1624 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "langage.y" /* yacc.c:1646  */
    { add_instruction (ARCTAN); }
#line 1630 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 185 "langage.y" /* yacc.c:1646  */
    { add_instruction (ARCSIN); }
#line 1636 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 186 "langage.y" /* yacc.c:1646  */
    { add_instruction (ARCCOS); }
#line 1642 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 187 "langage.y" /* yacc.c:1646  */
    { add_instruction (EXP); }
#line 1648 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "langage.y" /* yacc.c:1646  */
    {  }
#line 1654 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 189 "langage.y" /* yacc.c:1646  */
    { add_instruction (ADD); }
#line 1660 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 190 "langage.y" /* yacc.c:1646  */
    { add_instruction (SUB); }
#line 1666 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 191 "langage.y" /* yacc.c:1646  */
    { add_instruction (MULT); }
#line 1672 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "langage.y" /* yacc.c:1646  */
    { add_instruction (DIV); }
#line 1678 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 193 "langage.y" /* yacc.c:1646  */
    { add_instruction (POW); }
#line 1684 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "langage.y" /* yacc.c:1646  */
    { add_instruction (MOD); }
#line 1690 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 195 "langage.y" /* yacc.c:1646  */
    { add_instruction (FACT);}
#line 1696 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "langage.y" /* yacc.c:1646  */
    { add_instruction (EXP); }
#line 1702 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 197 "langage.y" /* yacc.c:1646  */
    { add_instruction (LOG); }
#line 1708 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 198 "langage.y" /* yacc.c:1646  */
    { add_instruction (LN);  }
#line 1714 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 199 "langage.y" /* yacc.c:1646  */
    { add_instruction (ABS); }
#line 1720 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "langage.y" /* yacc.c:1646  */
    { add_instruction (SQRT); }
#line 1726 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 201 "langage.y" /* yacc.c:1646  */
    { add_instruction (HASARD); }
#line 1732 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 204 "langage.y" /* yacc.c:1646  */
    { }
#line 1738 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 205 "langage.y" /* yacc.c:1646  */
    { add_instruction (SUP); }
#line 1744 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 206 "langage.y" /* yacc.c:1646  */
    { add_instruction (SUPEQ); }
#line 1750 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "langage.y" /* yacc.c:1646  */
    { add_instruction (INF); }
#line 1756 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 208 "langage.y" /* yacc.c:1646  */
    { add_instruction (INFEQ); }
#line 1762 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 209 "langage.y" /* yacc.c:1646  */
    { add_instruction (ISEQ); }
#line 1768 "langage.bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 210 "langage.y" /* yacc.c:1646  */
    { add_instruction (ISDIFF); }
#line 1774 "langage.bison.cpp" /* yacc.c:1646  */
    break;


#line 1778 "langage.bison.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 212 "langage.y" /* yacc.c:1906  */


int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

//Fonction factorielle
int fact(const int n)
{
    int res = 1;
    for(int i = 2; i <= n; i++)
        res*=i;
    return res;
}

// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
    case ADD      : return "ADD";
    case MULT     : return "MUL"; 
    case POW      : return "POW";    //puissance
    case FACT     : return "FACT";   //factorielle
    case EXP      : return "EXP";    //exponentielle
    case LOG      : return "LOG";    //logarithme
    case LN       : return "LN";     //logarithmeNeperien
    case SIN      : return "SIN";    //sinus
    case COS      : return "COS";    //cosinus
    case TAN      : return "TAN";    //tangente
    case ARCSIN   : return "ARCSIN"; //arcsinus
    case ARCCOS   : return "ARCCOS"; //arccosinus
    case ARCTAN   : return "ARCTAN"; //arctangente   
    case ABS      : return "ABS";
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    case PRINT    : return "OUT";
    case ASSIGN   : return "MOV";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
}

// Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
printf("\n------- Exécution du programme ---------\n");
stack<double> pile;

int ic = 0;  // compteur instruction
double r1, r2;  // des registres

  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
      auto ins = code_genere[ic];
      switch (ins.code){
        case ADD:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1+r2);
            ic++;
          break;

        case SUB:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r2-r1);
            ic++;
          break;
        
        case MULT:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1*r2);
            ic++;
          break;

        case DIV:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1/r2);
            ic++;
          break;

        case POW:               //puissance
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(pow(r2,r1));
            ic++;
          break;

         case FACT:              //factorielle
            r1 = pile.top();    
            pile.pop(); 
            pile.push(fact(r1));
            ic++;
          break; 
        

        case EXP:               //exponentielle
            r1 = pile.top();    
            pile.pop(); 

            pile.push(exp(r1));
            ic++;
          break;

        case LOG:               //logarithme
            r1 = pile.top();    
            pile.pop(); 

            pile.push(log10(r1));
            ic++;
          break;

        case LN:                //logarithmeNeperien
            r1 = pile.top();    
            pile.pop(); 

            pile.push(log(r1));
            ic++;
          break;

        case SUP:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1<r2);
            ic++;
          break;

        case SUPEQ:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1<=r2);
            ic++;
          break;

        case INF:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1>r2);
            ic++;
          break;

        case INFEQ:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1>=r2);
            ic++;
          break;

        case ISEQ:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r1==r2);
            ic++;
          break;

        case ISDIFF:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(r2!=r1);
            ic++;
          break;

        case SIN:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(sin(r1));
            ic++;
          break;

        case COS:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(cos(r1));
            ic++;
          break;

        case COSH:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            pile.push(cosh(r1));
            ic++;
          break;

        case TAN:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();

            pile.push(tan(r1));
            ic++;
          break;

        case ARCSIN:               //arcsinus
            r1 = pile.top();    
            pile.pop(); 

            pile.push(asin(r1));
            ic++;
          break;
        
        case ARCCOS:               //arccosinus
            r1 = pile.top();    
            pile.pop(); 

            pile.push(acos(r1));
            ic++;
          break;
        
        case ARCTAN:               //arctangente
            r1 = pile.top();    
            pile.pop(); 

            pile.push(atan(r1));
            ic++;
          break;

        case ABS:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            pile.push(abs(r1));
            ic++;
          break;

        case SQRT:
            r1 = pile.top();
            pile.pop();
            pile.push(sqrt(r1));
            ic++;
          break;

        case MOD:
            r1 = pile.top();
            pile.pop();
            r2 = pile.top();
            pile.pop();
            pile.push(fmod(r2, r1));
            ic++;
          break;

        case ASSIGN:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();
            variables[ins.name] = r1;
            ic++;
          break;

        case PRINT:
            r1 = pile.top();    // Récuperer la tête de pile;
            pile.pop();
            cout << "→ " << r1 << endl; 
            ic++;
        break;

        case NUM:   // pour un nombre, on empile
            pile.push(ins.value);
            ic++;
          break;

        case JMP:
            if (ins.value != -999) 
              ic = ins.value;
            else
              ic = adresses[ins.name];
          break;

        case JMPCOND: 
             r1 = pile.top();    // Récuperer la tête de pile;
             pile.pop();
             if ( r1 != 0 ) 
                ic++;
             else 
                ic = (int)ins.value;             
          break;
        case HASARD:
            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();
            pile.push((rand() % (int)(r1 - r2 + 1)) + r2);
            ic++;
          break;

        case VAR:    // je consulte la table de symbole et j'empile la valeur de la variable
            try {
                pile.push(variables.at(ins.name));
                ic++;
            }
            catch(...) {
                variables[ins.name] = 0;
                pile.push(variables.at(ins.name));
                ic++;
            }
          break;
      }
  }
}

int main(int argc, char **argv) {
  printf("-----------------\nParseur Cédille++ en exécution !\n");

  // Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();

/*  //FOR DEBUG PORPOSES
  for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << i 
         << '\t'
         << print_code(instruction.code) 
         << '\t'
         << instruction.value 
         << '\t' 
         << instruction.name 
         << endl;
  }
*/
  execution(code_genere, variables);

  return 0;
}
