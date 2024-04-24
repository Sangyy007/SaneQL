/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOT = 258,
    LET = 259,
    DATE = 260,
    FOREIGNCALL = 261,
    CONCAT = 262,
    TEXT = 263,
    TYPE = 264,
    OPERATOR = 265,
    FILTER = 266,
    MAP = 267,
    ORDERBY = 268,
    PROJECT = 269,
    IDENTIFIER = 270,
    COMMA = 271,
    COLON = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACE = 275,
    RBRACE = 276,
    LT = 277,
    LT_EQ = 278,
    GT = 279,
    GT_EQ = 280,
    EQ = 281,
    NEQ = 282,
    ASC = 283,
    DESC = 284,
    LIMIT = 285,
    EOF = 286
  };
#endif
/* Tokens.  */
#define DOT 258
#define LET 259
#define DATE 260
#define FOREIGNCALL 261
#define CONCAT 262
#define TEXT 263
#define TYPE 264
#define OPERATOR 265
#define FILTER 266
#define MAP 267
#define ORDERBY 268
#define PROJECT 269
#define IDENTIFIER 270
#define COMMA 271
#define COLON 272
#define LPAREN 273
#define RPAREN 274
#define LBRACE 275
#define RBRACE 276
#define LT 277
#define LT_EQ 278
#define GT 279
#define GT_EQ 280
#define EQ 281
#define NEQ 282
#define ASC 283
#define DESC 284
#define LIMIT 285
#define EOF 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
