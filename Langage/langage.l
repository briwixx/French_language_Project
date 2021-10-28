
%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "langage.bison.hpp"
%}

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? {  yylval.valeur = atof(yytext); return NUM; }
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos { return COS;  }
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
quatre   { yylval.valeur = 4. ; return NUM; }
plus    { return '+';}
fois    { return '*'; }
Si      { return SI;}
Alors   { return ALORS;}
Sinon   { return SINON;}
FinSi   { return FINSI;}

[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;  return VAR; }

\+     {  return yytext[0];  }  // la même chose que return '+'  
"-"    {  return '-'; }
"*"    {  return '*'; }
"/"    {  return '/'; }
"="|"<-"    {  return '='; }
">"    { return SUP; }
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nLe programme est correct!\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
