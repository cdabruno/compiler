/* Made by Bruno Correa and Alexadre Crestani */

%{
    #include "ast.h"
    #include "lex.yy.h"
    int yyerror();
    int getLineNumber(void);
    int getLineNumber(void);

    Ast *ast;
    %}

%union {
    Hash *symbol;
    Ast *ast;
}

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

%token<symbol> TK_IDENTIFIER

%token<symbol> LIT_INTEGER
%token<symbol> LIT_FLOAT
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING

%token TOKEN_ERROR

%type<ast> program
%type<ast> declaration_lst
%type<ast> declaration
%type<ast> literal
%type<ast> type_kw
%type<ast> literals_lst
%type<ast> parameters_lst
%type<ast> parameters
%type<ast> command
%type<ast> command_lst
%type<ast> assign
%type<ast> expr
%type<ast> expr_lst
%type<ast> if
%type<ast> ife
%type<ast> while
%type<ast> read
%type<ast> print
%type<ast> print_lst
%type<ast> print_expr
%type<ast> return

%left '&'
%left '|'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '.' '/'
%left '~'

%%

program: declaration_lst { ast = $1; }
    ;

declaration_lst: declaration declaration_lst { $$ = createAstNode(AST_DECL, 0, $1, $2, 0, 0, getLineNumber()); }
    | { $$ = 0; }
    ;
    
declaration: type_kw TK_IDENTIFIER '(' literal ')' ';' { $$ = createAstNode(AST_VAR_DEC, 0, $1, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()), $4, 0, getLineNumber()); }
    | type_kw TK_IDENTIFIER '[' LIT_INTEGER ']' literals_lst ';' { $$ = createAstNode(AST_ARR_DEC, 0, $1, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()), 
                                                                    createAstNode(AST_INT, $4, 0, 0, 0, 0, getLineNumber()), $6, getLineNumber()); }
    | type_kw TK_IDENTIFIER '(' parameters_lst ')' '{' command_lst '}' { $$ = createAstNode(AST_FUNC_DEC, 0, $1, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()),
                                                                            $4, $7, getLineNumber()); }
    | ';' { $$ = 0; }
    ;

literal: LIT_CHAR { $$ = createAstNode(AST_CHAR, $1, 0, 0, 0, 0, getLineNumber()); }
    | LIT_INTEGER { $$ = createAstNode(AST_INT, $1, 0, 0, 0, 0, getLineNumber()); }
    | LIT_FLOAT { $$ = createAstNode(AST_FLOAT, $1, 0, 0, 0, 0, getLineNumber()); }
    ;

type_kw: KW_CHAR { $$ = createAstNode(AST_KW_CHAR, 0, 0, 0, 0, 0, getLineNumber()); }
    | KW_INT { $$ = createAstNode(AST_KW_INT, 0, 0, 0, 0, 0, getLineNumber()); }
    | KW_FLOAT { $$ = createAstNode(AST_KW_FLOAT, 0, 0, 0, 0, 0, getLineNumber()); }
    ;

literals_lst: literal literals_lst { $$ = createAstNode(AST_LIT_LIST, 0, $1, $2, 0, 0, getLineNumber()); }
    | { $$ = 0; }
    ;

parameters_lst: parameters parameters_lst { $$ = createAstNode(AST_PARAM_LIST, 0, $1, $2, 0, 0, getLineNumber()); }
    | { $$ = 0; }
    ;

parameters: type_kw TK_IDENTIFIER { $$ = createAstNode(AST_PARAM, 0, $1, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()), 0, 0, getLineNumber()); }
    ;

command: '{' command_lst '}' { $$ = createAstNode(AST_COMMAND_BLOCK, 0, $2, 0, 0, 0, getLineNumber()); }
    | assign { $$ = $1; }
    | if { $$ = $1; }
    | ife { $$  = $1; }
    | while { $$ = $1; }
    | read { $$ = $1; }
    | print { $$ = $1; }
    | return { $$ = $1; }
    | { $$ = 0; }
    ;

command_lst: command ';' command_lst { $$ = createAstNode(AST_COMMAND_LIST, 0, $1, $3, 0, 0, getLineNumber()); }
    | command { $$ = $1; }
    ;

assign: TK_IDENTIFIER ASSIGNMENT expr { $$ = createAstNode(AST_ASSIGN, 0, createAstNode(AST_IDENTIFIER, $1, 0, 0, 0, 0, getLineNumber()), $3, 0, 0, getLineNumber()); }
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr { $$ = createAstNode(AST_ASSIGN_ARR, 0, createAstNode(AST_IDENTIFIER, $1, 0, 0, 0, 0, getLineNumber()), $3, $6, 0, getLineNumber()); }
    ;

expr: '(' expr ')' { $$ = createAstNode(AST_EXPR_PAR, 0, $2, 0, 0, 0, getLineNumber()); }
    | TK_IDENTIFIER { $$ = createAstNode(AST_EXPR_IDENTIFIER, 0, createAstNode(AST_IDENTIFIER, $1, 0, 0, 0, 0, getLineNumber()), 0, 0, 0, getLineNumber()); }
    | TK_IDENTIFIER '[' expr ']' { $$ = createAstNode(AST_EXPR_ARR, 0, createAstNode(AST_IDENTIFIER, $1, 0, 0, 0, 0, getLineNumber()), $3, 0, 0, getLineNumber()); }
    | literal { $$ = $1; }
    | expr '+' expr { $$ = createAstNode(AST_EXPR_SUM, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '-' expr { $$ = createAstNode(AST_EXPR_SUB, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '.' expr { $$ = createAstNode(AST_EXPR_MULT, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '/' expr { $$ = createAstNode(AST_EXPR_DIV, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '<' expr { $$ = createAstNode(AST_EXPR_LT, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '>' expr { $$ = createAstNode(AST_EXPR_GT, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr OPERATOR_LE expr { $$ = createAstNode(AST_EXPR_LE, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr OPERATOR_GE expr { $$ = createAstNode(AST_EXPR_GE, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr OPERATOR_EQ expr { $$ = createAstNode(AST_EXPR_EQ, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr OPERATOR_DIF expr { $$ = createAstNode(AST_EXPR_DIFF, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '&' expr { $$ = createAstNode(AST_EXPR_AND, 0, $1, $3, 0, 0, getLineNumber()); }
    | expr '|' expr { $$ = createAstNode(AST_EXPR_OR, 0, $1, $3, 0, 0, getLineNumber()); }
    | '~' expr { $$ = createAstNode(AST_EXPR_NOT, 0, $2, 0, 0, 0, getLineNumber()); }
    | TK_IDENTIFIER '(' expr_lst ')' { $$ = createAstNode(AST_EXPR_FUNC_CALL, 0, createAstNode(AST_IDENTIFIER, $1, 0, 0, 0, 0, getLineNumber()), $3, 0, 0, getLineNumber()); }
    ;

expr_lst: expr expr_lst { $$ = createAstNode(AST_EXPR_LIST, 0, $1, $2, 0, 0, getLineNumber()); }
    | { $$ = 0; }
    ;

if: KW_IF '(' expr ')' command { $$ = createAstNode(AST_IF, 0, $3, $5, 0, 0, getLineNumber()); }
    ;

ife: KW_IF '(' expr ')' command KW_ELSE command { $$ = createAstNode(AST_IFE, 0, $3, $5, $7, 0, getLineNumber()); }
    ;

while: KW_WHILE '(' expr ')' command { $$ = createAstNode(AST_WHILE, 0, $3, $5, 0, 0, getLineNumber()); }
    ;

read: KW_READ TK_IDENTIFIER { $$ = createAstNode(AST_READ, 0, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()), 0, 0, 0, getLineNumber()); }
    | KW_READ TK_IDENTIFIER '[' expr ']' { $$ = createAstNode(AST_READ_ARR, 0, createAstNode(AST_IDENTIFIER, $2, 0, 0, 0, 0, getLineNumber()), $4, 0, 0, getLineNumber()); }
    ;

print: KW_PRINT print_lst { $$ = createAstNode(AST_PRINT, 0, $2, 0, 0, 0, getLineNumber()); }
    ;

print_lst: print_expr print_lst { $$ = createAstNode(AST_PRINT_LIST, 0, $1, $2, 0, 0, getLineNumber()); }
    | { $$ = 0; }
    ;

print_expr: LIT_STRING { $$ = createAstNode(AST_STRING, $1, 0, 0, 0, 0, getLineNumber()); }
    | expr { $$ = $1; }
    ;

return: KW_RETURN expr { $$ = createAstNode(AST_RETURN, 0, $2, 0, 0, 0, getLineNumber()); }
    ;

%%

int yyerror(){
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}