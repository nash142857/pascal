#include "common.h"
enum class cal_op{
	PLUS, MINUS, MUL, DIV, MOD, AND
};
class expr{
private:
	string codestr;
public:
	static string genfromop(expr a, expr b, cal_op op);
	string gencode();
	void setcode(string _codestr){
		codestr = _codestr;
	}
};
enum class expr_op{
	GE,GT,LE,LT,EQ,UEQ;
};
class expression{
private:
	expr_op op;
	expression * lchild;
	expr * expr;
public:
	string gencode();
}