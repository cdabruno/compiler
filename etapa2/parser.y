/* Made by Bruno Correa and Alexadre Crestani */

%{
    int yyerror();
    %}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT

%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token ASSIGNMENT
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token TK_IDENTIFIER

%token LIT_INTEGER
%token LIT_FLOAT
%token LIT_CHAR
%token LIT_STRING

%token TOKEN_ERROR

%left '&'
%left '|'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '.' '/'
%left '~'

%%

program: declaration_lst
    ;

declaration_lst: declaration ';' declaration_lst
    | type_kw TK_IDENTIFIER '(' parameters_lst ')' '{' command_lst '}' declaration_lst
    |
    ;
    
declaration: type_kw TK_IDENTIFIER '(' literal ')'
    | type_kw TK_IDENTIFIER '[' LIT_INTEGER ']' literals_lst 
    |
    ;

literal: LIT_CHAR
    | LIT_INTEGER
    | LIT_FLOAT
    ;

type_kw: KW_CHAR
    | KW_INT
    | KW_FLOAT
    ;

literals_lst: literal literals_lst
    |
    ;

parameters_lst: parameters parameters_lst
    |
    ;

parameters: type_kw TK_IDENTIFIER
    ;

command: '{' command_lst '}'
    | assing
    | if
    | ife
    | while
    | read
    | print
    | return
    |
    ;

command_lst: command ';' command_lst
    | command
    ;

assing: TK_IDENTIFIER ASSIGNMENT expr 
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr
    ;

expr: '(' expr ')' 
    | TK_IDENTIFIER 
    | TK_IDENTIFIER '[' expr ']' 
    | literal 
    | expr '+' expr 
    | expr '-' expr 
    | expr '.' expr 
    | expr '/' expr 
    | expr '<' expr 
    | expr '>' expr 
    | expr OPERATOR_LE expr 
    | expr OPERATOR_GE expr 
    | expr OPERATOR_EQ expr 
    | expr OPERATOR_DIF expr 
    | expr '&' expr 
    | expr '|' expr 
    | '~' expr 
    | TK_IDENTIFIER '(' expr_lst ')' 
    ;

expr_lst: expr expr_lst
    |
    ;

if: KW_IF '(' expr ')' command
    ;

ife: KW_IF '(' expr ')' command KW_ELSE command
    ;

while: KW_WHILE '(' expr ')' command
    ;

read: KW_READ TK_IDENTIFIER
    | KW_READ TK_IDENTIFIER '[' expr ']'
    ;

print: KW_PRINT print_lst
    ;

print_lst: print_expr print_lst
    |
    ;

print_expr: LIT_STRING
    | expr
    ;

return: KW_RETURN expr
    ;

%%

int yyerror(){
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}