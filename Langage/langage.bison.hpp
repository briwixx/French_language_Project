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
    SI = 270,
    TANT_QUE = 271,
    FIN_TANT_QUE = 272,
    ALORS = 273,
    SINON = 274,
    FINSI = 275,
    SUP = 276,
    SUPEQ = 277,
    INF = 278,
    INFEQ = 279,
    ABS = 280,
    PRINT = 281,
    ASSIGN = 282,
    GOTO = 283,
    LABEL = 284,
    JMP = 285,
    JMPCOND = 286,
    POW = 287,
    FACT = 288,
    EXP = 289,
    LOG = 290,
    LN = 291,
    HASARD = 292,
    ADD = 293,
    SUB = 294,
    MULT = 295,
    DIV = 296
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

#line 112 "langage.bison.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LANGAGE_BISON_HPP_INCLUDED  */
