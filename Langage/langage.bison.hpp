/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 61 "langage.y" /* yacc.c:1909  */

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 52 "langage.bison.hpp" /* yacc.c:1909  */

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
    ABS = 284,
    MOD = 285,
    PRINT = 286,
    ASSIGN = 287,
    GOTO = 288,
    LABEL = 289,
    JMP = 290,
    JMPCOND = 291,
    POW = 292,
    FACT = 293,
    EXP = 294,
    LOG = 295,
    LN = 296,
    HASARD = 297,
    ADD = 298,
    SUB = 299,
    MULT = 300,
    DIV = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "langage.y" /* yacc.c:1909  */

  double valeur;
  char nom[50];
  type_adresse adresse;  

#line 117 "langage.bison.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LANGAGE_BISON_HPP_INCLUDED  */
