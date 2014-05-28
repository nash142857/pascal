%{
	void yyerror(char * s);
	extern int yylex();
	#include "const_record.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>	
%}

%union{
	char * _str;
	int _int;
	double _double;
	base_type * _type;
	char _char;
	key_value_tuple * _tuple;
}

%token  REAL CHAR LP RP LB RB DOT COMMA COLON MUL DIV PLUS MINUS ID GE GT LE LT EQUAL ASSIGN INTEGER REAL CHAR STRING CONST SEMI 

%type <_str> ID
%type <_tuple> const_value
%type <_int> INTEGER
%type <_double> REAL
%type <_char> CHAR
%type <_str> STRING

%%
const_part : CONST LB const_expr_list RB

const_expr_list: const_expr_list  ID EQUAL const_value SEMI 
	| ID EQUAL const_value SEMI 
	;
const_value: 
	
	

%%
void yyerror(char * s){
	printf("%s\n", s);
}
int main()
{
}


 INTEGER {
		union_set value;
		value._int = atoi(yytext);
		type_ptr ptr(new base_type(INTEGER));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
}
	| REAL{
		union_set value;
		value._double = atof(yytext);
		type_ptr ptr(new base_type(REAL));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	| CHAR{
		union_set value;
		value._char = yytext[1];
		type_ptr ptr(new base_type(CHAR));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	| STRING{
		union_set value;
		value._str = strdup(yytext);
		type_ptr ptr(new base_type(STRING));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	;

	{
		auto c_r = const_record::singleton();
		string s($1);
		if(!c_r _> insert(s, $3 -> first, vector <string>(), $3 -> second)){
			yyerror("symbol table error");
		};
	}


