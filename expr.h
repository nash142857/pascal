#pragma once
#include "common.h"
#include "type_value.h"
#include "var_record.h"
#define UNDEFINE_EXPR "undefine_expr"
class base_expr{
public:
	string codestr;
	bool flag;
	bool type_id;//表达式结果 整数或则浮点 true表示浮点数
	bool expr_value_type(){

	}
	base_expr(){
		codestr = UNDEFINE_EXPR;
		flag = false;
	}
	virtual void gencode(int &i){//i 表示是放在哪个寄存器中
	}
	void setcodestr(const string & _codestr){
		codestr = _codestr;
	}
};

class unary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr> child;
	void gencode(int &i){
		int k = i;
		child -> gencode(i);
		switch(op){
		case MINUS_TYPE:
			codestr = "SUB R" + itoa(k) + ", R1, R" + itoa(k);
			break;
		case NOT_TYPE:
			codestr = "SUB R" + itoa(k) + ", R1, R" + itoa(k);
			codestr += "\nADDI R" + itoa(k) + ", R" + itoa(k) + ", -1";
		}
		cout << codestr << endl;
	}
	bool expr_value_type(){
		if(flag){
			return type_id;
		}
		type_id = child -> expr_value_type();
		flag = true;
		return type_id;
	}

};


class binary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr>  lchild;
	shared_ptr <base_expr> rchild;
	void gencode(int & i){
		int k = i;
		int l = ++i;
		lchild -> gencode(i);
		int r = i;
		rchild -> gencode(i);
		switch(op){
		case MUL_TYPE:
			codestr = "MUL R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r);
			break;
		case PLUS_TYPE:
			codestr = "ADD R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r); 
		case MINUS_TYPE:
			codestr = "SUB R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r); 	
		}
		cout << codestr << endl;
	}
	bool expr_value_type(){
		if(flag){
			return type_id;
		}
		type_id = lchild -> expr_value_type() && rchild -> expr_value_type();
		flag = true;
		return type_id;
	}
};

class leaf_node_value: public base_expr{
public:
	value_set value;
	int type_id;
	void gencode(int &i){
		string str = value_set_to_str(type_id, value);
		switch(type_id){
		case INT_TYPE:
			codestr = "ADDI R" + itoa(i) + " , R1," + str;
			break;
		case REAL_TYPE:
			codestr = "ADDI F" + itoa(i) + " , R1," + str;	
		}
		++i;
		cout << codestr << endl;
	}
	bool expr_value_type(){
		if(type_id == INT_TYPE)
			return false;
		else
			return true;
	}
}; 
class record_node_value: public base_expr{
public:
	string id;
	string member;
	void gencode(int & i){
		auto off = var_record::single() -> searchoffset(id, member);
		switch(off.second){
		case INT_TYPE:
			codestr = "LW R" + itoa(i) + " " + itoa(off.first) + "($SP)";
			break;
		case REAL_TYPE:
			codestr = "L.D R" + itoa(i) + " " + itoa(off.first) + "($SP)" + 
			"\n" + "MTC1 R" + itoa(i) + ", F" + itoa(1);
		}
		++i;
		cout << codestr << endl;
	}
	bool expr_value_type(){
		if(flag)
			return type_id;
		auto off = var_record::single() -> searchoffset(id, member);
		if(off.second == INT_TYPE)
			type_id = false;
		else
			type_id = true;
		flag = true;
		return type_id;
	}
};



