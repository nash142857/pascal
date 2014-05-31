#pragma once
#include "expr.h"
enum class stmt_type {

};
class base_stmt{
public:
	virtual string gencode() = 0;
	virtual void setcode(const string & _codestr){
		codestr = _codestr;
	}
};
class if_stmt:public base_stmt{
private:
	expression * judge;
	base_stmt * lchild;
	base_stmt * rchild;
public:
	string gencode();
};
class goto_stmt:public base_stmt{
private:
	int addr;//address to go
public:
	string gencode();
};
class assign_stmt:public base_stmt{
private:
	private codestr;
public:
	void setcode(const string & _codestr){
		codestr = _codestr;
	}
	void gencode(const string & _codestr){
		return codestr;
	}
};
class while_stmt: public base_stmt{
	
};
class for_stmt: public base_stmt{

};
class repeat_stmt: public base_stmt{

};
class case_stmt: public base_stmt{

}