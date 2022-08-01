 /* Made by Bruno Correa and Alexandre Crestani */

#include <stdio.h>
#include <stdlib.h>

int yylex();
extern char *yytext;
extern FILE *yyin;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "Call: ./etapa1.out file_name\n");
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  if (yyin == NULL)
  {
    printf("Cannot open file %s\n", argv[1]);
    exit(1);
  }

  initMe();
  yyparse();
  hashPrint();
  
  exit(0);
}
