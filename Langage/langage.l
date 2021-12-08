%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "langage.bison.hpp"
%}

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? { // s'il s'agit d'un nombre on le stocke dans le champ "valeur"
                                      yylval.valeur = atof(yytext);
                                      return NUM;
                                    }
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }

Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN; } //tangante
ArcSin|Arcsin|ARCSIN|arcsin|arcsinus|arcSinus|ARCSINUS { return ARCSIN;  } //arcsin
ArcCos|Arccos|ARCCOS|arccos|arccosinus|arcCosinus|ARCCOS { return ARCCOS;  } //arccos
ArcTan|ARCTAN|arctan|arctangente|ArcTangente|ARCTANGENTE { return ARCTAN;}  //arctan
<<<<<<< Updated upstream
puissance|Puissance { return POW;} //puissance
factorielle|Factorielle|fact|Fact|FACT  { return FACT;} //factorielle
=======
puissance|Puissance|PUISSANCE|"^" { return POW;} //puissance
factorielle|Factorielle|fact|Fact|FACT|"!"  { return FACT;} //factorielle
>>>>>>> Stashed changes
exponentielle|Exponentielle|exp|Exp|EXP { return EXP;} //exponentielle
logarithme|Logarithme|log|Log { return LOG;} //logarithme
logarithmeneperien|LogarithmeNeperien|Logarithmeneperien|logarithmeNeperien|ln|Ln { return LN;} //logarithmeNeperien

un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
plus    { return ADD; }
fois    { return MULT; }
Si      { return SI;}
Alors   { return ALORS;}
Sinon   { return SINON;}
FinSi   { return FINSI;}
Imprime { return PRINT;}
GoTo    { return GOTO;}
Hasard  { return HASARD; }

@[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;
                          return LABEL;
                       }

[A-Za-z_][A-Za-z_0-9]* { // s'il s'agit d'une variable, on stocke son nom dans le champ "nom"
                         strcpy( yylval.nom, yytext) ;
                         return VAR;
                       }

\+|plus|Plus|PLUS     {  return ADD; }
"-"|moins|Moins|MOINS {  return SUB; }
"*"|fois|Fois|FOIS    {  return MULT; }
"/"|divise                   {  return DIV; }
"="|"<-"    {  return '='; }
">"|superieur|Superieur|SUPERIEUR    { return SUP; }
"<"|inferieur|Inferieur|INFERIEUR    { return INF; }
">="|superieur\sou\segal   { return SUPEQ; }
"<="|inferieur\sou\segal    { return INFEQ; }
":"    { return ':'; }
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nLe programme est correct!\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
