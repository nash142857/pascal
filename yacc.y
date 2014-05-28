%{
	#include "common.h"
	void yyerror(char * s);
	extern int yylex();

%}
%union{

}

%token  REAL CHAR LP RP LB RB DOT COMMA COLON MUL DIV PLUS MINUS ID GE GT LE LT EQUAL ASSIGN INTEGER REAL CHAR STRING CONST SEMI

%%
const_part : CONST LB const_expr_list RB

const_expr_list: const_expr_list  ID EQUAL const_value SEMI 
	| ID EQUAL const_value SEMI

const_value: INTEGER
	| REAL
	| CHAR
	| STRING
	;


%%
void yyerror(char * s){
	printf("%s\n", s);
	flag = 0;
}
int main()
{
}
