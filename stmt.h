#pragma once
#include "expr.h"
class base_stmt{
public:
	string codestr;
	base_stmt(){
		codestr = UNDEFINE_EXPR;
	}
	virtual void gencode(){
	}
	void setcode(const string & _codestr){
		codestr = _codestr;
	}
};
class if_stmt:public base_stmt{
public:
	shared_ptr <base_expr>  judge;
	shared_ptr <base_stmt> lchild;
	shared_ptr <base_stmt> rchild;
};
class goto_stmt:public base_stmt{
public:
	int addr;//address to go

};
class assign_stmt:public base_stmt{
public:
	shared_ptr <base_expr> value;

};
class record_assign: public assign_stmt{
public:
	string id;
	string member;
	void gencode(){
		int i = 2;
		value -> gencode(i);
		auto in = var_record::single() -> searchoffset(id, member);
		codestr = "SW R2, " +  itoa(in.first) + "($SP)";
		cout << codestr << endl;
	}

};
class normal_assign: public assign_stmt{
public:
	string id;
	void gencode(){
		int i =  2;	
		value -> gencode(i);
		auto in = var_record::single() -> searchoffset(id);
		codestr = "SW R2, " +  itoa(in.first) + "($SP)";
		cout << codestr << endl;
	}
};
class arr_assign: public assign_stmt{
public:
	shared_ptr <base_expr> index;
	string id;
};

class while_stmt: public base_stmt{
};
class for_stmt: public base_stmt{

};
class repeat_stmt: public base_stmt{

};
class case_stmt: public base_stmt{

};