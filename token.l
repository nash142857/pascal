%{
    #include "y.tab.h"

%}

LP "("
RP ")"
LB "["
RB "]"
DOT "."
COMMA ": "
COLON ", "
MUL "*"
DIV "/"
PLUS "+"
MINUS "-"
ID [A-Za-z][A-Za-z0-9_]*
GE ">="
GT ">"
LE "<="
LT "<"
EQUAL "="
ASSIGN ":="
INTEGER [0-9]+
REAL [0-9]+"."[0-9]+
CHAR "'"."'"
STRING """"""
%%



%%
int yywrap(){
	return 1;
}
