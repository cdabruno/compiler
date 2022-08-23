 /* Made by Bruno Correa and Alexandre Crestani */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "lex.yy.h"
#include "y.tab.h"
#include "decompiler.h"
#include "semantic.h"


int yylex();
void initMe(void);
extern Ast *ast;
extern char *yytext;
extern FILE *yyin;
extern int semanticErrors;

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

  //printAst(ast, 0);
  semanticAnalysis(ast);
  
  if(semanticErrors > 0){
    exit(4);
  }

  
  decompile(ast, outFile);

  exit(0);
}
