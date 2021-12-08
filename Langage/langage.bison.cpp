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
#line 1 "langage.y"

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

  class instruction{
  public:
    instruction (const int &c, const double &v=0, const string &n="") {code = c; value = v; name = n;};
    int code;
    double value;     //éventuellement une valeur si besoin
    string name;      //ou une référence pour la table des données
  };

  //Déclaration de la map qui associe
  //les noms des variables à leur valeur
  //(La table de symboles)
  map<string,double> variables;
  int ic = 0;

  //Cette map sert à stocker les adresses associées aux labels (GoTo).
  //Pour info, il est possible de faire un saut vers une étiquette
  //qui n'est pas encore déclarée (Saut vers le futur)
  //En gros, les sauts GoTo ne se font pas uniquement vers l'arrière.
  //Je vous laisse gérer les problèmes créés par le Goto :
  //- Saut vers une étiquette inexistante (ni avant, ni après)
  //- Duplication de labels (Déterminisme !!!)
  //Ne parlons pas, comme dans l'exmeple, des sauts de blocs de déclarations,
  //ou des bloc entremêlés, ou... ou ...
  //Vous avez compris pourquoi il est banni ?
  map<string,int> adresses;


  //Structure pour accueillir le code généré
  //(sone de code ou code machine ou assembleur)
  vector <instruction> code_genere;

  //Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
  int add_instruction(const int &c, const double &v=0, const string &n="") {
      code_genere.push_back(instruction(c,v,n));
      ic++;
      return 0;
   };



#line 129 "langage.bison.cpp"

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

#include "langage.bison.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_SIN = 5,                        /* SIN  */
  YYSYMBOL_COS = 6,                        /* COS  */
  YYSYMBOL_TAN = 7,                        /* TAN  */
  YYSYMBOL_ARCSIN = 8,                     /* ARCSIN  */
  YYSYMBOL_ARCCOS = 9,                     /* ARCCOS  */
  YYSYMBOL_ARCTAN = 10,                    /* ARCTAN  */
  YYSYMBOL_SI = 11,                        /* SI  */
  YYSYMBOL_TANT_QUE = 12,                  /* TANT_QUE  */
  YYSYMBOL_FIN_TANT_QUE = 13,              /* FIN_TANT_QUE  */
  YYSYMBOL_ALORS = 14,                     /* ALORS  */
  YYSYMBOL_SINON = 15,                     /* SINON  */
  YYSYMBOL_FINSI = 16,                     /* FINSI  */
  YYSYMBOL_SUP = 17,                       /* SUP  */
  YYSYMBOL_SUPEQ = 18,                     /* SUPEQ  */
  YYSYMBOL_INF = 19,                       /* INF  */
  YYSYMBOL_INFEQ = 20,                     /* INFEQ  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_GOTO = 23,                      /* GOTO  */
  YYSYMBOL_LABEL = 24,                     /* LABEL  */
  YYSYMBOL_JMP = 25,                       /* JMP  */
  YYSYMBOL_JMPCOND = 26,                   /* JMPCOND  */
  YYSYMBOL_POW = 27,                       /* POW  */
  YYSYMBOL_FACT = 28,                      /* FACT  */
  YYSYMBOL_EXP = 29,                       /* EXP  */
  YYSYMBOL_LOG = 30,                       /* LOG  */
  YYSYMBOL_LN = 31,                        /* LN  */
  YYSYMBOL_HASARD = 32,                    /* HASARD  */
  YYSYMBOL_ADD = 33,                       /* ADD  */
  YYSYMBOL_SUB = 34,                       /* SUB  */
  YYSYMBOL_MULT = 35,                      /* MULT  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_37_n_ = 37,                     /* '\n'  */
  YYSYMBOL_38_ = 38,                       /* ':'  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_bloc = 43,                      /* bloc  */
  YYSYMBOL_label = 44,                     /* label  */
  YYSYMBOL_instruction = 45,               /* instruction  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_condition = 52                  /* condition  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      37,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   109,   109,   110,   112,   113,   118,   119,   120,   121,
     122,   126,   131,   126,   142,   143,   145,   142,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   175,   176,   177,
     178,   179
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "VAR", "SIN",
  "COS", "TAN", "ARCSIN", "ARCCOS", "ARCTAN", "SI", "TANT_QUE",
  "FIN_TANT_QUE", "ALORS", "SINON", "FINSI", "SUP", "SUPEQ", "INF",
  "INFEQ", "PRINT", "ASSIGN", "GOTO", "LABEL", "JMP", "JMPCOND", "POW",
  "FACT", "EXP", "LOG", "LN", "HASARD", "ADD", "SUB", "MULT", "DIV",
  "'\\n'", "':'", "'='", "'('", "')'", "$accept", "bloc", "label",
  "instruction", "$@1", "$@2", "$@3", "$@4", "$@5", "expr", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -69,     1,   -69,   -35,    96,   -69,   -69,   -18,   134,   134,
     134,   134,   134,   134,   -17,   -69,   134,     0,   134,   134,
     134,   134,    -5,   134,    -1,    46,   134,   -69,   -69,   -69,
      46,   -69,   -69,    46,   134,    -3,    46,   -69,   -69,   -69,
     -69,   -69,   134,    -7,   -69,   134,   134,   134,   134,   134,
      46,    13,    -2,   134,    58,   -69,   -69,    85,    85,   -69,
     -69,   134,   134,   134,   134,    14,    11,    42,    46,    46,
      46,    46,   -69,    16,   -69,    40,   -69,    18,   -69,   -69,
     -11,    94,    43,    55,   -69,    34,   -69,    98,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,     6,     5,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,    19,    21,    22,
      23,    25,    26,    24,     0,     0,     8,    10,    32,    33,
      34,    35,     0,     0,     3,     0,     0,     0,     0,     0,
       9,    37,     0,     0,     0,    20,    31,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    11,     0,    36,     0,    15,     0,     2,     2,
       4,     4,     0,     0,    17,     0,     2,     4,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -68,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    -4,
      19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     4,    24,    75,    83,    35,    78,    82,    51,
      52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,     2,   -16,     5,    28,    29,    30,    31,    32,    33,
      80,    81,    36,     3,    38,    39,    40,    41,    87,    43,
      45,    26,    50,    34,    37,     3,    46,    47,    48,    49,
      61,    62,    63,    64,    55,    42,    44,    53,    54,    65,
      45,    56,    57,    58,    59,    60,    46,    47,    48,    49,
      67,    72,    73,    76,    77,    79,    84,    68,    69,    70,
      71,     6,    27,     8,     9,    10,    11,    12,    13,    45,
      85,    86,    66,    45,     0,    46,    47,    48,    49,    46,
      47,    48,    49,    74,     0,    45,    18,    19,    20,    21,
      22,    46,    47,    48,    49,     0,     0,     0,    23,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   -12,
       0,     0,    45,     0,    88,     0,     0,    16,     3,    17,
      48,    49,     3,     0,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,    23,     6,    27,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,    23
};

static const yytype_int8 yycheck[] =
{
       4,     0,    13,    38,     8,     9,    10,    11,    12,    13,
      78,    79,    16,    24,    18,    19,    20,    21,    86,    23,
      27,    39,    26,    40,    24,    24,    33,    34,    35,    36,
      17,    18,    19,    20,    41,    40,    37,    40,    42,    41,
      27,    45,    46,    47,    48,    49,    33,    34,    35,    36,
      54,    37,    41,    37,    14,    37,    13,    61,    62,    63,
      64,     3,     4,     5,     6,     7,     8,     9,    10,    27,
      15,    37,    53,    27,    -1,    33,    34,    35,    36,    33,
      34,    35,    36,    41,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    15,
      -1,    -1,    27,    -1,    16,    -1,    -1,    21,    24,    23,
      35,    36,    24,    -1,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,     0,    24,    44,    38,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    21,    23,    28,    29,
      30,    31,    32,    40,    45,    51,    39,     4,    51,    51,
      51,    51,    51,    51,    40,    48,    51,    24,    51,    51,
      51,    51,    40,    51,    37,    27,    33,    34,    35,    36,
      51,    51,    52,    40,    51,    41,    51,    51,    51,    51,
      51,    17,    18,    19,    20,    41,    52,    51,    51,    51,
      51,    51,    37,    41,    41,    46,    37,    14,    49,    37,
      43,    43,    50,    47,    13,    15,    37,    43,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    46,    47,    45,    48,    49,    50,    45,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     0,     1,     2,     3,
       2,     0,     0,    14,     0,     0,     0,    10,     1,     1,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     5,     1,     3,     3,
       3,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
  case 5: /* label: LABEL ':'  */
#line 113 "langage.y"
                   { //Lorsque je rencontre un label
                     //je stocke le numéro d'instruction actelle
                     //dans la table des adresses. C'est tout!
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1238 "langage.bison.cpp"
    break;

  case 7: /* instruction: expr  */
#line 119 "langage.y"
                           {  }
#line 1244 "langage.bison.cpp"
    break;

  case 8: /* instruction: PRINT expr  */
#line 120 "langage.y"
                           { add_instruction(PRINT); }
#line 1250 "langage.bison.cpp"
    break;

  case 9: /* instruction: VAR '=' expr  */
#line 121 "langage.y"
                           { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1256 "langage.bison.cpp"
    break;

  case 10: /* instruction: GOTO LABEL  */
#line 122 "langage.y"
                           {  //J'insère un JMP vers une adresse que je ne connais pas encore.
                              //J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                              add_instruction(JMP, -999, (yyvsp[0].nom));
                           }
#line 1265 "langage.bison.cpp"
    break;

  case 11: /* $@1: %empty  */
#line 126 "langage.y"
                                        { //Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                                          //lorsqu'elle sera connue (celle du JC)
                                          (yyvsp[-4].adresse).jc = ic;
                                          add_instruction(JMPCOND); }
#line 1274 "langage.bison.cpp"
    break;

  case 12: /* $@2: %empty  */
#line 131 "langage.y"
                                        { //Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                                          //lorsqu'elle sera connue (celle du JMP)
                                          (yyvsp[-8].adresse).jmp = ic;
                                          add_instruction(JMP);
                                          //Je mets à jour l'adresse du saut conditionnel
                                          code_genere[(yyvsp[-8].adresse).jc].value = ic;
                                        }
#line 1286 "langage.bison.cpp"
    break;

  case 13: /* instruction: SI '(' condition ')' '\n' $@1 ALORS '\n' bloc $@2 SINON '\n' bloc FINSI  */
#line 140 "langage.y"
                                        { // Je mets à jour l'adresse du saut inconditionnel
                                          code_genere[(yyvsp[-13].adresse).jmp].value = ic; }
#line 1293 "langage.bison.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 142 "langage.y"
                                              { (yyvsp[0].adresse).jmp = ic; }
#line 1299 "langage.bison.cpp"
    break;

  case 15: /* $@4: %empty  */
#line 143 "langage.y"
                                              { (yyvsp[-5].adresse).jc = ic;
                                                add_instruction(JMPCOND); }
#line 1306 "langage.bison.cpp"
    break;

  case 16: /* $@5: %empty  */
#line 145 "langage.y"
                                              { 
                                                add_instruction(JMP, (yyvsp[-7].adresse).jmp);
                                              }
#line 1314 "langage.bison.cpp"
    break;

  case 17: /* instruction: TANT_QUE $@3 '(' condition ')' '\n' $@4 bloc $@5 FIN_TANT_QUE  */
#line 148 "langage.y"
                                              { 
                                                code_genere[(yyvsp[-9].adresse).jc].value = ic; 
                                              }
#line 1322 "langage.bison.cpp"
    break;

  case 18: /* expr: NUM  */
#line 154 "langage.y"
                         { add_instruction (NUM, (yyvsp[0].valeur));   }
#line 1328 "langage.bison.cpp"
    break;

  case 19: /* expr: VAR  */
#line 155 "langage.y"
                         { add_instruction (VAR, 0, (yyvsp[0].nom));  }
#line 1334 "langage.bison.cpp"
    break;

  case 20: /* expr: '(' expr ')'  */
#line 156 "langage.y"
                         {  }
#line 1340 "langage.bison.cpp"
    break;

  case 21: /* expr: SIN expr  */
#line 157 "langage.y"
                         { add_instruction (SIN); }
#line 1346 "langage.bison.cpp"
    break;

  case 22: /* expr: COS expr  */
#line 158 "langage.y"
                         { add_instruction (COS); }
#line 1352 "langage.bison.cpp"
    break;

  case 23: /* expr: TAN expr  */
#line 159 "langage.y"
                         { add_instruction (TAN); }
#line 1358 "langage.bison.cpp"
    break;

  case 24: /* expr: ARCTAN expr  */
#line 160 "langage.y"
                         { add_instruction (ARCTAN); }
#line 1364 "langage.bison.cpp"
    break;

  case 25: /* expr: ARCSIN expr  */
#line 161 "langage.y"
                         { add_instruction (ARCSIN); }
#line 1370 "langage.bison.cpp"
    break;

  case 26: /* expr: ARCCOS expr  */
#line 162 "langage.y"
                         { add_instruction (ARCCOS); }
#line 1376 "langage.bison.cpp"
    break;

  case 27: /* expr: expr ADD expr  */
#line 163 "langage.y"
                         { add_instruction (ADD); }
#line 1382 "langage.bison.cpp"
    break;

  case 28: /* expr: expr SUB expr  */
#line 164 "langage.y"
                         { add_instruction (SUB); }
#line 1388 "langage.bison.cpp"
    break;

  case 29: /* expr: expr MULT expr  */
#line 165 "langage.y"
                         { add_instruction (MULT);}
#line 1394 "langage.bison.cpp"
    break;

  case 30: /* expr: expr DIV expr  */
#line 166 "langage.y"
                         { add_instruction (DIV); }
#line 1400 "langage.bison.cpp"
    break;

  case 31: /* expr: expr POW expr  */
#line 167 "langage.y"
                         { add_instruction (POW); }
#line 1406 "langage.bison.cpp"
    break;

  case 32: /* expr: FACT expr  */
#line 168 "langage.y"
                         { add_instruction (FACT);}
#line 1412 "langage.bison.cpp"
    break;

  case 33: /* expr: EXP expr  */
#line 169 "langage.y"
                         { add_instruction (EXP); }
#line 1418 "langage.bison.cpp"
    break;

  case 34: /* expr: LOG expr  */
#line 170 "langage.y"
                         { add_instruction (LOG); }
#line 1424 "langage.bison.cpp"
    break;

  case 35: /* expr: LN expr  */
#line 171 "langage.y"
                         { add_instruction (LN);  }
#line 1430 "langage.bison.cpp"
    break;

  case 36: /* expr: HASARD '(' expr expr ')'  */
#line 172 "langage.y"
                                   { add_instruction (HASARD); }
#line 1436 "langage.bison.cpp"
    break;

  case 37: /* condition: expr  */
#line 175 "langage.y"
                              { }
#line 1442 "langage.bison.cpp"
    break;

  case 38: /* condition: expr SUP expr  */
#line 176 "langage.y"
                              { add_instruction (SUP); }
#line 1448 "langage.bison.cpp"
    break;

  case 39: /* condition: expr SUPEQ expr  */
#line 177 "langage.y"
                              { add_instruction (SUPEQ); }
#line 1454 "langage.bison.cpp"
    break;

  case 40: /* condition: expr INF expr  */
#line 178 "langage.y"
                              { add_instruction (INF); }
#line 1460 "langage.bison.cpp"
    break;

  case 41: /* condition: expr INFEQ expr  */
#line 179 "langage.y"
                              { add_instruction (INFEQ); }
#line 1466 "langage.bison.cpp"
    break;


#line 1470 "langage.bison.cpp"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 181 "langage.y"


int yyerror(char *s) {
    printf("%s : %s\n", s, yytext);
}


//Petite fonction pour mieux voir le code généré
//(au lieu des nombres associés au tokens)
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
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    case PRINT    : return "OUT";
    case ASSIGN   : return "MOV";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
}

//Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere,
                 map<string,double> &variables )
{
printf("\n------- Exécution du programme ---------\n");
stack<double> pile;

int ic = 0;  //compteur instruction
double r1, r2;  //des registres

  while (ic < code_genere.size()){   //tant que nous ne sommes pas à la fin du programme
      auto ins = code_genere[ic];
      switch (ins.code){
        case ADD:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1+r2);
            ic++;
          break;

        case SUB:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1-r2);
            ic++;
          break;

        case MULT:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1*r2);
            ic++;
          break;

        case DIV:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1-r2);
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

        /* case FACT:              //factorielle
            r1 = pile.top();    
            pile.pop(); 
            
            double factorial(r1){
              if(r1>1){
                return factorial(r1-1)*r1;
              }
              return 1;
            }

            pile.push(factorial(r1));
            ic++;
          break; 
        */

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
        
        case SIN:               //sinus
            r1 = pile.top();    
            pile.pop(); 

            pile.push(sin(r1));
            ic++;
          break;
        
        case COS:               //cosinus
            r1 = pile.top();    
            pile.pop(); 

            pile.push(cos(r1));
            ic++;
          break;

         case TAN:               //tangente
            r1 = pile.top();    
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
        
        case SUP:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1>r2);
            ic++;
          break;

        case SUPEQ:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1>=r2);
            ic++;
          break;

        case INF:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1<r2);
            ic++;
          break;

        case INFEQ:
            r1 = pile.top();    
            pile.pop();

            r2 = pile.top();    
            pile.pop();

            pile.push(r1<=r2);
            ic++;
          break;

        case ASSIGN:
            r1 = pile.top();    
            pile.pop();
            variables[ins.name] = r1;
            ic++;
          break;

        case PRINT:
            r1 = pile.top();    
            pile.pop();
            cout << "$ " << r1 << endl;
            ic++;
        break;

        case NUM:   //pour un nombre, on empile
            pile.push(ins.value);
            ic++;
          break;

        case JMP:
            if (ins.value != -999) //Est-ce un GoTo ?
              ic = ins.value;
            else
              //je récupère l'adresse à partir de la table
              ic = adresses[ins.name];
          break;

        case JMPCOND:
             r1 = pile.top();    
             pile.pop();
             if ( r1 != 0 )
                ic++;
             else
                ic = (int)ins.value;
          break;

        case HASARD:
            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

        case VAR:    //je consulte la table de symbole et j'empile la valeur de la variable
             //Si elle existe bien sur...
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
  printf("-----------------\nLangage V3.0 / Deep Thought\n");

  //Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();


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

  execution(code_genere, variables);

  return 0;
}
