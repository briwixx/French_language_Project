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
Sinh|SINH|sinh|sinush|Sinush|SINUSH { return SINH;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Cosh|COSH|cosh|cosinush|Cosinush|COSINUSH {return COSH;}
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN;  }
Tanh|TANH|tanh|tangenteh|Tangenteh|TANGENTEH {return TANH;}
pi|Pi|PI { return PI;}
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
plus    { return ADD;}
fois    { return MULT; }
Si      { return SI;}
Tant_que  { return TANT_QUE; }
Fin_tant_que  { return FIN_TANT_QUE; }
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

\+     {  return ADD; }  
"-"    {  return SUB; }
"*"    {  return MULT; }
"/"    {  return DIV; }
"="|"<-"    {  return '='; }
">"    { return SUP; }
"<"    { return INF; }
">="   { return SUPEQ; }
"<="   { return INFEQ; }
":"    { return ':'; }   
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nLe programme est correct!\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
