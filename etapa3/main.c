 /* Made by Bruno Correa and Alexandre Crestani */

#include <stdio.h>
#include <stdlib.h>

int yylex();
extern Ast *ast;
extern char *yytext;
extern FILE *yyin;

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    fprintf(stderr, "Call: ./etapa3.out file_name out_file_name\n");
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  if (yyin == NULL)
  {
    printf("Cannot open file %s\n", argv[1]);
    exit(1);
  }
  FILE *outFile = fopen(argv[2], "w");
  
  initMe();
  yyparse();
  hashPrint();
  decompile(ast, outFile);

  exit(0);
}
