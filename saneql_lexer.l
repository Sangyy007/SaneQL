%{
#include <iostream>
#include <string>
#include "parser.tab.h"
using namespace std;
using namespace saneql;

extern int yylval;
%}

%option noyywrap

%%
"let"                       { return LET; }
"date"                      { return DATE; }
"foreigncall"               { return FOREIGNCALL; }
"concat"                    { return CONCAT; }
"text"                      { return TEXT; }
"type"                      { return TYPE; }
"operator"                  { return OPERATOR; }
"filter"                    { return FILTER; }
"map"                       { return MAP; }
"orderby"                   { return ORDERBY; }
"project"                   { return PROJECT; }
"asc"                       { return ASC; }
"desc"                      { return DESC; }
"limit"                     { return LIMIT; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
"<"                         { return LT; }
"<="                        { return LT_EQ; }
">"                         { return GT; }
">="                        { return GT_EQ; }
"=="                        { return EQ; }
"!="                        { return NEQ; }
","                         { return COMMA; }
":"                         { return COLON; }
"."                         { return DOT; } // Define the DOT token
[0-9]+                      { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*      { yylval = strdup(yytext); return IDENTIFIER; }
[ \t\n]                     ;  // Skip whitespace and newline
.                           { cerr << "Invalid character: " << yytext << endl; }
"."                         { return DOT; } // Define the DOT token

%%

int main() {
    yylex();
    return 0;
}

