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

[Ss][In][Nn]([Uu][Ss])? { return SIN;  }
[Ss][In][Nn]([Hh])?([Uu][Ss][Hh])? { return SINH;  }
[Cc][Oo][Ss]([In][Nn][Uu][Ss])? { return COS;  }
[Cc][Oo][Ss][Hh]?([In][Nn][Uu][Ss][Hh])? {return COSH;}
[Tt][Aa][Nn]([Gg][Ee][Nn][Tt][Ee])? { return TAN;  }
[Tt][Aa][Nn][Hh]([Gg][Ee][Nn][Tt][Ee][Hh])? {return TANH;}
[Aa][Rr][Cc][Ss][In][Nn]([Uu][Ss])? { return ARCSIN;  }
[Aa][Rr][Cc][Oo][Ss]([In][Nn][Uu][Ss])? { return ARCCOS;  }
[Aa][Rr][Cc][Tt][Aa][Nn]([Gg][Ee][Nn][Tt][Ee])? { return ARCTAN;}  
[Pp][Uu][Ii][Ss]{2}[Aa][Nn][Cc][Ee]|"^" { return POW;}
[Ff][Aa][Cc][Tt]([Oo][Rr][Ii][Ee][Ll]{2}[Ee])?|"!"  { return FACT;}
[Ee][Xx][Pp]([Oo][Nn][Ee][Nn][Tt][Ii][Ee][Ll]{2}[Ee])? { return EXP;}
[Ll][Oo][Gg]([Aa][Rr][Ii][Tt][Hh][Mm][Ee])? { return LOG;}
[Ll][Oo][Gg][Aa][Rr][Ii][Tt][Mm][Ee]([ ]|[_])?[Nn][Ee][Pp][Ee][Rr][Ii][Ee][Nn]|[Ll][Nn] { return LN;}
[Aa][Bb][Ss]([Oo][Ll][Uu][Ee])? { return ABS; }
[Rr][Aa][Cc][Ii][Nn][Ee](([ ]|[_])?[Cc][Aa][Rr]{2}[Ee]{2})? { return SQRT; }
[Mm][Oo][Dd][Uu][Ll][Oo] { return MOD; }
[Pp][Ii] { return PI;}

[Uu][Nn]      { yylval.valeur = 1. ; return NUM; }
[Dd][Ee][Uu][Xx]    { yylval.valeur = 2. ; return NUM; }
[Tt][Rr][Oo][Ii][Ss]   { yylval.valeur = 3. ; return NUM; }
[Qq][Uu][Aa][Tt][Rr][Ee]	{ yylval.valeur = 4. ; return NUM; }
[Cc][Ii][Nn][Qq]	  { yylval.valeur = 5. ; return NUM; }
[Ss][Ii][Xx]	    { yylval.valeur = 6. ; return NUM; }
[Ss][Ee][Pp][Tt]	{ yylval.valeur = 7. ; return NUM; }
[Hh][Uu][Ii][Tt]	{ yylval.valeur = 8. ; return NUM; }
[Nn][Ee][Uu][Ff]	{ yylval.valeur = 9. ; return NUM; }
[Dd][Ii][Xx]	    { yylval.valeur = 10. ; return NUM; }
[Oo][Nn][Zz][Ee]	  { yylval.valeur = 11. ; return NUM; }
[Dd][Oo][Uu][Zz][Ee]	  { yylval.valeur = 12. ; return NUM; }
[Tt][Rr][Ee][Ii][Zz][Ee]	{ yylval.valeur = 13. ; return NUM; }
[Qq][Uu][Aa][Tt][Oo][Rr][Zz][Ee]	{ yylval.valeur = 14. ; return NUM; }
[Qq][Uu][Ii][Nn][Zz][Ee]	{ yylval.valeur = 15. ; return NUM; }
[Ss][Ee][Ii][Zz][Ee]	  { yylval.valeur = 16. ; return NUM; }
[Ss][Ii]      { return SI; }
[Tt][Aa][Nn][Tt]([ ]|[_])?[Qq][Uu][Ee]  { return TANT_QUE; }
[Ff][Ii][Nn]([ ]|[_])?[Tt][Aa][Nn][Tt]([ ]|[_])?[Qq][Uu][Ee]  { return FIN_TANT_QUE; }
[Pp][Oo][Uu][Rr]      { return POUR; }
[Ff][Ii][Nn]([_]|[ ])?[Pp][Oo][Uu][Rr]  { return FIN_POUR; }
[Aa][Ll][Oo][Rr][Ss]   { return ALORS;}
[Ss][Ii][Nn][Oo][Nn]   { return SINON;}
[Ff][Ii][Nn]([ ]|[_])?[Ss][Ii]   { return FINSI;}
[Ii][Mm][Pp][Rr][Ii][Mm][Ee] { return PRINT;}
[Aa][Ll]{2}[Ee][Rr]([ ]|[_])?[Aa]    { return GOTO;} 
[Hh][Aa][Ss][Aa][Rr][Dd]  { return HASARD; }

@[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;
                          return LABEL;
                       }

[A-Za-z_][A-Za-z_0-9]* { // s'il s'agit d'une variable, on stocke son nom dans le champ "nom"
                         strcpy( yylval.nom, yytext) ;
                         return VAR;
                       }

\+|[Pp][Ll][Uu][Ss]     {  return ADD; }  
"-"|[Mm][Oo][Ii][Nn][Ss]    {  return SUB; }
"*"|[Ff][Oo][Ii][Ss]   {  return MULT; }
"/"|[Dd][Ii][Vv][Ii][Ss][Ee]    {  return DIV; }
"=="   { return ISEQ; }
"!="|[Dd][Ii][Ff]{2}[Ee][Rr][Ee][Nn][Tt]   { return ISDIFF; }
"="|"<-"    {  return '='; }
">"|[Ss][Uu][Pp][Ee][Rr][Ii][Ee][Uu][Rr]([ ]|[_])?[Aa]    { return SUP; }
"<"|[Ii][Nn][Ff][Ee][Rr][Ii][Ee][Uu][Rr]([ ]|[_])?[Aa]    { return INF; }
">="|[Ss][Uu][Pp][Ee][Rr][Ii][Ee][Uu][Rr]([ ]|[_])?[Aa]([ ]|[_])?[Oo][Uu]([ ]|[_])?[Ee][Gg][Aa][Ll]   { return SUPEQ; }
"<="|[Ii][Nn][Ff][Ee][Rr][Ii][Ee][Uu][Rr]([ ]|[_])?[Aa]([ ]|[_])?[Oo][Uu]([ ]|[_])?[Ee][Gg][Aa][Ll]   { return INFEQ; }
":"    { return ':'; }   
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nLe programme est correct!\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
