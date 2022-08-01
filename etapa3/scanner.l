/* Made by Bruno Correa and Alexadre Crestani */

%{
#include "hash.h"
#include "ast.h"
#include "y.tab.h"
#include "decompiler.h"


int running = 1;
int lineNumber = 1;

int isRunning(void);

int getLineNumber(void);

void initMe(void);

%}

%x COMMENT

%%


 /* Reserved words */
"char"      {return KW_CHAR;}
"int"       {return KW_INT;}
"float"     {return KW_FLOAT;}
"if"        {return KW_IF;}
"else"      {return KW_ELSE;}
"while"     {return KW_WHILE;}
"read"      {return KW_READ;}
"print"     {return KW_PRINT;}
"return"    {return KW_RETURN;}

 /* Special characters */
[\;\(\)\[\]\{\}\+\-\.\/\<\>\&\|\~]  {return yytext[0];}

 /* Operators */
"<-"        {return ASSIGNMENT;}
"<="        {return OPERATOR_LE;}
">="        {return OPERATOR_GE;}
"=="        {return OPERATOR_EQ;}
"!="        {return OPERATOR_DIF;}

 /* Ignore tabs and spaces*/
[ \t]

 /* Count new lines */
[\n]        {++lineNumber;}

 /* Identifiers */
[a-zA-Z_]*  {yylval.symbol = hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}

 /* Literals */
[0-9]+                  {yylval.symbol = hashInsert(yytext, LIT_INTEGER);   return LIT_INTEGER;}
[0-9]+,[0-9]+           {yylval.symbol = hashInsert(yytext, LIT_FLOAT);     return LIT_FLOAT;}
\'[ -~]\'               {yylval.symbol = hashInsert(yytext, LIT_CHAR);      return LIT_CHAR;}
\"(\\.|[^"\\\n])*\"     {yylval.symbol = hashInsert(yytext, LIT_STRING);    return LIT_STRING;}

 /* Comments */
"##".*
"\\#"           {BEGIN(COMMENT);}
<COMMENT>"#\\"  {BEGIN(INITIAL);}
<COMMENT>"\n"   {++lineNumber;}
<COMMENT>.

 /* Token error */
.   {return TOKEN_ERROR;}
%%

#include "y.tab.c"
#include "hash.c"
#include "ast.c"
#include "decompiler.c"
#include "main.c"


int isRunning(void) {
    return running;
}

int getLineNumber(void) {
    return lineNumber;
}

int yywrap() {
    running = 0;
    return 1;
}

void initMe(void) {
    hashInit();
    running = 1;
    lineNumber = 1;
}
