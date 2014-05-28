%{
    #include "y.tab.h"

%}
CONST "const" 
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
STRING "'".*"'" 
SEMI ";" 
%%
CONST  {return CONST;}
LP  {return LP;}
RP  {return RP;}
LB {return LB;}
RB {return RB;}
DOT  {return DOT;}
COMMA  {return COMMA;}
COLON  {return COLON;}
MUL 	{return MUL;}
DIV {return DIV;}
PLUS  {return PLUS;}
MINUS  {return MINUS;}
ID  {return ID;}
GE  {return GE;}
GT  {return GT;}
LE  {return LE;}
LT  {return LT;}
EQUAL {return EQUAL;}
ASSIGN {return ASSIGN;}
INTEGER  {return INTEGER;}
REAL {return REAL;}
CHAR  {return CHAR;}
STRING  {return STRING;}
SEMI {return SEMI;}
. {return yytext[0];}

%%
int yywrap(){
	return 1;
}
