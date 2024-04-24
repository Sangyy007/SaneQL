%{
#include <iostream>
#include <string>
#include "saneql_lexer.l"
using namespace saneql;
using namespace std;

extern int yylex();
extern char* yytext;
void yyerror(const char*);

%}
%token DOT

%token LET DATE FOREIGNCALL CONCAT TEXT TYPE OPERATOR FILTER MAP ORDERBY PROJECT IDENTIFIER COMMA COLON LPAREN RPAREN LBRACE RBRACE LT LT_EQ GT GT_EQ EQ NEQ ASC DESC LIMIT EOF

%%

program : statement_list EOF
        ;

statement_list : statement
               | statement_list statement
               ;

statement : let_statement
          | expression
          ;

let_statement : LET IDENTIFIER LPAREN parameter_list RPAREN COLON expression
              ;

parameter_list : /* empty */
               | parameter
               | parameter_list COMMA parameter
               ;

parameter : IDENTIFIER
          | IDENTIFIER COLON expression
          ;

expression : function_call
           | binary_operation
           | unary_operation
           | filter_operation
           | map_operation
           | orderby_operation
           | project_operation
           ;

function_call : IDENTIFIER LPAREN argument_list RPAREN
              ;

argument_list : /* empty */
              | expression
              | argument_list COMMA expression
              ;

binary_operation : expression OPERATOR expression
                 ;

unary_operation : IDENTIFIER LPAREN expression RPAREN
                ;

filter_operation : IDENTIFIER DOT IDENTIFIER LT expression
                 ;

map_operation : IDENTIFIER DOT IDENTIFIER LPAREN parameter_list RPAREN
              ;

orderby_operation : ORDERBY LPAREN order_list RPAREN
                  ;

order_list : order_expression
           | order_list COMMA order_expression
           ;

order_expression : IDENTIFIER ASC
                 | IDENTIFIER DESC
                 ;

project_operation : PROJECT LPAREN projection_list RPAREN
                  ;

projection_list : projection_expression
                | projection_list COMMA projection_expression
                ;

projection_expression : IDENTIFIER
                      | IDENTIFIER COLON IDENTIFIER
                      ;

%%

void yyerror(const char* s) {
    cerr << "Parser error: " << s << endl;
}

int main() {
    yyparse();
    return 0;
}

