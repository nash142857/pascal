%{
	void yyerror(char * s);
	extern int yylex();
	#include "const_record.h"
	#include "type_record.h"
	#include "var_record.h"
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
	vector <string> * _vt;
	vector < pair <string, type_ptr> > * _field;
}

%token  LP RP LB RB DOT COMMA COLON MUL DIV PLUS MINUS ID GE GT LE LT EQUAL ASSIGN INTEGER REAL CHAR STRING CONST SEMI VAR PROGRAM TYPE SYS_TYPE RECORD DF ARRAY BP END BEGINN MOD UNEQUAL DR NOT AND

%type <_str> ID
%type <_tuple> const_value
%type <_int> INTEGER
%type <_double> REAL
%type <_char> CHAR
%type <_str> STRING
%type <_type> array_type_decl
%type <_type> type_decl
%type <_type> record_type_decl
%type <_str> SYS_TYPE
%type <_type> simple_type_decl
%type <_field> field_decl
%type <_field> field_decl_list
%type <_vt> name_list
%type <_field> var_decl
%type <_str> term
%type <_str> factor
%%
program : program_head routine DOT
program_head: PROGRAM ID SEMI
routine: routine_head routine_body
routine_head: const_part type_part var_part 
sub_routine: routine_head routine_body

const_part : CONST  const_expr_list 
		{
			const_record::singleton() -> debug();
		}
		|
		;
const_expr_list: const_expr_list  ID EQUAL const_value SEMI {
		auto c_r = const_record::singleton();
		vector <string> tmp;
		c_r -> insert($2, $4 -> first, tmp, $4 -> second);
	}
	| ID EQUAL const_value SEMI {
		auto c_r = const_record::singleton();
		vector <string> tmp;
		c_r -> insert($1, $3 -> first, tmp, $3 -> second);
	}
	;
const_value: INTEGER {
		value_set value;
		value._int = $1;
		type_ptr ptr(new base_type(INT_TYPE));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
}
	| REAL{
		value_set value;
		value._double = $1;
		type_ptr ptr(new base_type(REAL_TYPE));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	| CHAR{
		value_set value;
		value._char = $1;
		type_ptr ptr(new base_type(CHAR_TYPE));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	| STRING{
		value_set value;
		value._str = $1;
		type_ptr ptr(new base_type(STR_TYPE));
		$$ = new key_value_tuple();
		$$ -> first = ptr;
		$$ -> second = value;
	}
	;
type_part: TYPE type_decl_list 
	|
	;
name_list: name_list COLON ID {
		$1 -> push_back($3);
		$$ = $1;
	}
	| ID{
		$$ = new vector <string> ();
		$$ -> push_back($1);
	}
	;
type_decl_list : type_decl_list type_definition 
	| type_definition
	;
type_definition : ID EQUAL type_decl SEMI{
		shared_ptr <base_type> tmp($3);
		type_record::single() -> insert($1, tmp);	
	}
	;
type_decl: simple_type_decl {
		$$ = $1;
	}
	| array_type_decl{
		$$ = $1;
	}
	| record_type_decl{
		$$ = $1;
	}
	;
array_type_decl : ARRAY LB simple_type_decl RB DF type_decl{
		$$ = new arr_type();
		((arr_type * )$$) -> nxt.reset($6);
		((arr_type * )$$) -> index.reset($3);
	}
	;
record_type_decl: RECORD field_decl_list END{
		$$ = new record_type();
		((record_type * )$$) -> vt = *$2;
	}
	;
field_decl_list: field_decl_list field_decl {
		for(auto i = $2 -> begin(); i != $2 -> end(); ++i){
			$1 -> push_back(*i);
		}
		delete $2;
		$$ = $1;
	}
	| field_decl{
		$$ = $1;
	}
	;
field_decl: name_list  COMMA type_decl SEMI{
		$$ = new vector < pair <string, type_ptr> >();
		for(auto i = $1 -> begin(); i != $1 -> end(); ++i){
			type_ptr tmp($3);
			$$ -> push_back(make_pair(*i, tmp));
		}
		delete $3;
	}
	;

simple_type_decl : SYS_TYPE
	{
		if(strcmp($1, "int")){
			$$ = new base_type(INT_TYPE);
		}
		else
			if(strcmp($1, "real")){
				$$ = new base_type(REAL_TYPE);
			}
			else
			if(strcmp($1, "char")){
				$$ = new base_type(CHAR_TYPE);
			}
			else
			if(strcmp($1, "string")){
				$$ = new base_type(STR_TYPE);
			}
	}
	| LP name_list RP
	{
		discrete_type * tmp = new discrete_type();
		for(auto i = $2 -> begin(); i != $2 -> end(); ++i){
			tmp -> index.push_back(*i);
		}
		$$ = tmp;
	}
	| const_value DOT DOT const_value{
		continue_type * tmp = new continue_type();
		tmp -> left = *$1;
		tmp -> right = *$4;
		delete $1;
		delete $4;	
	}
	| MINUS const_value DOT DOT const_value{
			if($2 -> first -> gettype() == INT_TYPE){
				$2 -> second._int = -$2 -> second._int;
			}
			if($2 -> first -> gettype() == REAL_TYPE){
				$2 -> second._double = -$2 -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *$2;
			tmp -> right = *$5;
			delete $5;
			delete $2;
	}
	| MINUS const_value DOT DOT MINUS const_value{
			if($2 -> first -> gettype() == INT_TYPE){
				$2 -> second._int = -$2 -> second._int;
			}
			if($2 -> first -> gettype() == REAL_TYPE){
				$2 -> second._double = -$2 -> second._double;
			}
			if($6 -> first -> gettype() == INT_TYPE){
				$6 -> second._int = -$6 -> second._int;
			}

			if($6 -> first -> gettype() == REAL_TYPE){
				$6 -> second._double = -$6 -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *$2;
			tmp -> right = *$6;
			delete $2;
			delete $6;
	}
	;



var_part : VAR  var_decl_list 
	| 
	;
var_decl_list : var_decl_list var_decl 
	| var_decl
	;
var_decl: name_list COMMA type_decl SEMI{
		for(auto i = $1 -> begin(); i != $1 -> end(); ++i){
			type_ptr tmp($3);
			if(!var_record::single() -> insert(*i, tmp)){
				yyerror("var_decl error");
			} 
		}	
	}
	;

routine_body: BEGINN stmt_list END
	;
stmt_list: stmt_list stmt SEMI
	|
	;

stmt: INTEGER COLON non_label_stmt | non_label_stmt

non_label_stmt:
	assign_stmt
	;

assign_stmt: ID ASSIGN expression
	| ID LB expression RB ASSIGN expression
	| ID DOT ID ASSIGN expression

expression: expression GE expr
	| expression GT expr
	| expression LE expr
	| expression LT expr
	| expression EQUAL expr
	| expression UNEQUAL expr
	| expr
	;

expr: expr PLUS term 
	| expr MINUS term
	| term
	;

term: term MUL factor
	| term DIV factor
	| term MOD factor
	| term AND factor{

	}
	| factor{
		$$ = $1;
	}
	;

factor: ID 
	| ID LP arg_list RP 
	| const_value{
		$$ = strdup(("ldc " + value_set_to_str($1 -> first, $1 -> second)).c_str());
	}
	| LP expression RP
	| NOT factor
	| MINUS factor
	| ID LB expression RB
	| ID DOT ID

arg_list: arg_list COMMA expression
	| expression
	;
%%
void yyerror(char * s){
	printf("%s\n", s);
	exit(0);
}
int main()
{
	printf("%d\n", yyparse());
}


 


