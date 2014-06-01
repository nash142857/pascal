%{
    #include "const_record.h"
    #include "type_record.h"
	#include "var_record.h"
	#include "stmt.h"
    #include "common.h"
    #include "expr.h"
	#include "y.tab.h"
%}

const "const"
var "var"
lp "(" 
rp ")"
lb "["
rb "]" 
dot "." 
comma ":"
colon "," 
mul "*"	
div "/" 
plus "+"
minus "-"
id [a-zA-Z][a-zA-Z0-9_]*
ge ">="  
gt ">"
le "<="
lt "<" 
equal "="
assign ":=" 
integer [0-9]+ 
real [0-9]+"."[0-9]+ 
char "'"."'" 
string "'".*"'" 
semi ";" 
program "program"
type "type"
sys_type int|string|real|char
record "record"
end "end"
array "array"
df "of"
begin "begin"
%%

{const}  {return CONST;}
{program} {return PROGRAM;}
{sys_type} {yylval._str = strdup(yytext);return SYS_TYPE;}
{record} {return RECORD;}
{end} {return END;}
{begin} {return BEGINN;}
{type} {return TYPE;}
{df} {return DF;}
{array} {return ARRAY;}
{var} {return VAR;}
{plus}  {return PLUS;}
{minus}  {return MINUS;}
{lp}  {return LP;}
{rp}  {return RP;}
{lb} {return LB;}
{rb} {return RB;}
{dot}  {return DOT;}
{comma} {return COMMA;}
{colon}  {return COLON;}
{mul}	{return MUL;}
{div} {return DIV;}
{id} {yylval._str = strdup(yytext);return ID;}
{ge}  {return GE;}
{gt}  {return GT;}
{le}  {return LE;}
{lt}  {return LT;}
{equal} {return EQUAL;}
{assign} {return ASSIGN;}
{integer}  {yylval._int = atoi(yytext);return INTEGER;}
{real} {yylval._double = atof(yytext);return REAL;}
{char}  {yylval._char = yytext[1];return CHAR;}
{string}  {
	int l = strlen(yytext);
	yylval._str = new char[l - 2];
	strncpy(yylval._str, yytext + 1, l - 2);return STRING;}
{semi} {return SEMI;}
\n {}
\t {}
" " {}
. {return yytext[0];}

%%

int yywrap(){
	return 1;
}
