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
ArcSin|Arcsin|ARCSIN|arcsin|arcsinus|arcSinus|ARCSINUS { return ARCSIN;  } //arcsin
ArcCos|Arccos|ARCCOS|arccos|arccosinus|arcCosinus|ARCCOS { return ARCCOS;  } //arccos
ArcTan|ARCTAN|arctan|arctangente|ArcTangente|ARCTANGENTE { return ARCTAN;}  //arctan
puissance|Puissance|PUISSANCE|"^" { return POW;} //puissance
factorielle|Factorielle|fact|Fact|FACT|"!"  { return FACT;} //factorielle
exponentielle|Exponentielle|exp|Exp|EXP { return EXP;} //exponentielle
logarithme|Logarithme|log|Log { return LOG;} //logarithme
logarithmeneperien|LogarithmeNeperien|Logarithmeneperien|logarithmeNeperien|ln|Ln { return LN;} //logarithmeNeperien
Absolue|absolue|ABS|abs|Abs { return ABS; }
Racine|racine|sqrt|SQRT { return SQRT; }
Modulo|modulo|MODULO { return MOD; }
pi|Pi|PI { return PI;}
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
quatre	{ yylval.valeur = 4. ; return NUM; }
cinq	  { yylval.valeur = 5. ; return NUM; }
six	    { yylval.valeur = 6. ; return NUM; }
sept	{ yylval.valeur = 7. ; return NUM; }
huit	{ yylval.valeur = 8. ; return NUM; }
neuf	{ yylval.valeur = 9. ; return NUM; }
dix	    { yylval.valeur = 10. ; return NUM; }
onze	  { yylval.valeur = 11. ; return NUM; }
douze	  { yylval.valeur = 12. ; return NUM; }
treize	{ yylval.valeur = 13. ; return NUM; }
quatorze	{ yylval.valeur = 14. ; return NUM; }
quinze	{ yylval.valeur = 15. ; return NUM; }
seize	  { yylval.valeur = 16. ; return NUM; }
plus    { return ADD;}
fois    { return MULT; }
Si      { return SI; }
Tant_que  { return TANT_QUE; }
Fin_tant_que  { return FIN_TANT_QUE; }
Pour      { return POUR; }
Fin_Pour  { return FIN_POUR; }
Alors   { return ALORS;}
Sinon   { return SINON;}
FinSi   { return FINSI;}
Imprime { return PRINT;}
AllerA    { return GOTO;} 
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
"=="   { return ISEQ; }
"!="   { return ISDIFF; }
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
