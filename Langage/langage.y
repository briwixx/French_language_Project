%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <string>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  // Déclaration de la map qui associe
  // les noms des variables à leur valeur
  map<string,double> variables ;

%}

%union {
  double valeur;
  char nom[50];
}

%token <valeur> NUM
%token <nom> VAR
%type <valeur> expr 
%token SIN
%token COS
%token SI
%token ALORS
%token SINON
%token FINSI
%token SUP

%right '+' '-'
%left '*' '/'

%%
bloc:  /* Epsilon */
     | bloc instruction '\n'   

instruction :   /* Epsilon, ligne vide */
            | expr         { printf ("\n"); }
            | VAR '=' expr {  }
            | SI '(' expr SUP expr ')' '\n'
              ALORS '\n'
                bloc
              SINON '\n'
                bloc
              FINSI               {  }

expr:  NUM               { printf ("%g ",$1);  }
     | VAR               {  }
     | SIN '(' expr ')'  {  }
     | COS '(' expr ')'  {  }
     | '(' expr ')'      {  }
     | expr '+' expr     {  printf ("+ "); }
     | expr '-' expr     {  }   		
     | expr '*' expr     {  printf ("* ");}		
     | expr '/' expr     {  }    
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

int main(int argc, char **argv) {
  printf("-----------------\nLangage  V1.0\n");

  // Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();						

  return 0;
}