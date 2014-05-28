/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REAL = 258,
     CHAR = 259,
     LP = 260,
     RP = 261,
     LB = 262,
     RB = 263,
     DOT = 264,
     COMMA = 265,
     COLON = 266,
     MUL = 267,
     DIV = 268,
     PLUS = 269,
     MINUS = 270,
     ID = 271,
     GE = 272,
     GT = 273,
     LE = 274,
     LT = 275,
     EQUAL = 276,
     ASSIGN = 277,
     INTEGER = 278,
     STRING = 279,
     CONST = 280,
     SEMI = 281
   };
#endif
/* Tokens.  */
#define REAL 258
#define CHAR 259
#define LP 260
#define RP 261
#define LB 262
#define RB 263
#define DOT 264
#define COMMA 265
#define COLON 266
#define MUL 267
#define DIV 268
#define PLUS 269
#define MINUS 270
#define ID 271
#define GE 272
#define GT 273
#define LE 274
#define LT 275
#define EQUAL 276
#define ASSIGN 277
#define INTEGER 278
#define STRING 279
#define CONST 280
#define SEMI 281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 7 "yacc.y"
{

}
/* Line 1529 of yacc.c.  */
#line 105 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

