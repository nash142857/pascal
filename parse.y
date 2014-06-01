%{
	void yyerror(char * s);
	extern int yylex();
	#include "const_record.h"
	#include "type_record.h"
	#include "var_record.h"
	#include "stmt.h"
	#include "expr.h"
	#include "type_value.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>	
	#include "common.h"
	vector <base_stmt *> vt;
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
	base_expr * _expr;
	base_stmt * _stmt;
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
%type <_expr> term
%type <_expr> factor
%type <_expr> expr
%type <_expr> expression
%type <_stmt> assign_stmt
%type <_stmt> non_label_stmt
%type <_stmt> stmt
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

expression: expression GE expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = GE_TYPE;
		$$ = tmp;
	}
	| expression GT expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = GT_TYPE;
		$$ = tmp;
	}
	| expression LE expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = LE_TYPE;
		$$ = tmp;
	}
	| expression LT expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = LT_TYPE;
		$$ = tmp;	
	}
	| expression EQUAL expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = EQUAL_TYPE;
		$$ = tmp;
	}
	| expression UNEQUAL expr{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = UNEQUAL_TYPE;
		$$ = tmp;
	}
	| expr{
		$$ = $1;
	}
	;

expr: expr PLUS term {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = PLUS_TYPE;
		$$ = tmp;
	}
	| expr MINUS term{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = MINUS_TYPE;
		$$ = tmp;
	}
	| term{
		$$ = $1;
	}
	;

term: term MUL factor{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = MUL_TYPE;
		$$ = tmp;
	}
	| term DIV factor{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = DIV_TYPE;
		$$ = tmp;
	}
	| term MOD factor{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = MOD_TYPE;
		$$ = tmp;
	}
	| term AND factor{
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset($1);
		tmp -> rchild.reset($3);
		tmp -> op = AND_TYPE;
		$$ = tmp;
	}
	| factor{
		$$ = $1;
	}
	;

factor: ID 
	| ID LP arg_list RP 
	| LP expression RP
	| NOT factor{
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset($2);
		tmp -> op = NOT;
		$$ = tmp;
	}
	| MINUS factor{
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset($2);
		tmp -> op = MINUS;
		$$ = tmp;
	}
	| ID LB expression RB{

	}	
	| ID DOT ID{
		record_node_value * tmp = new record_node_value();
		tmp -> id = $1;
		tmp -> member = $3;
		$$ = tmp;
	}
	|
	INTEGER{
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = INT_TYPE;
		tmp -> value._int = $1;
		$$ = tmp;
	}	
	|
	REAL{
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = REAL_TYPE;
		tmp -> value._double = $1;
		$$ = tmp;
	}
	;

arg_list: arg_list COMMA expression
	| expression
	;



stmt_list: stmt_list stmt SEMI{
		vt.push_back($2);
	}
	|stmt SEMI{
		vt.push_back($1);
	}
	;

stmt: INTEGER COLON non_label_stmt{
	} | non_label_stmt{
	}

non_label_stmt:
	assign_stmt{
	}
	;

assign_stmt: ID ASSIGN expression{
		normal_assign * tmp = new normal_assign();	
		tmp -> value.reset($3);
		tmp -> id = $1;
		$$ = tmp;
	}
	| ID LB expression RB ASSIGN expression{
		arr_assign * tmp = new arr_assign();
		tmp -> id = $1;
		tmp -> index.reset($3);
		tmp -> value.reset($6);
		$$ = tmp;
	}
	| ID DOT ID ASSIGN expression{
		record_assign * tmp = new record_assign();
		tmp -> id = $1;
		tmp -> member = $3;
		tmp -> value.reset($5);
		$$ = tmp;
	}
	;
%%
void yyerror(char * s){
	printf("%s\n", s);
	exit(0);
}
int main()
{
	printf("%d\n", yyparse());
	printf("XOR R1, R1, R1\n");
	var_record::single() -> gencode();
	for(int i = 0; i < vt.size(); ++i){
		vt[i] -> gencode();
		delete vt[i];
	}
}


 


