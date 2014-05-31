#pragma once
#include "common.h"
#define RECORD_TYPE 142857
#define ARR_TYPE 428571
#define INT_TYPE 285714
#define STR_TYPE 857142
#define CHAR_TYPE 571428
#define REAL_TYPE 714285
#define DISCRETE_TYPE 31413
#define CONTINUE_TYPE 14133
class base_type{
protected:
	int type_id;
public:
	base_type(int i = 0){
		type_id = i;
	}
	void set_type(const int i){
		type_id = i;
	}
	int gettype(){
		return type_id;
	}
};
typedef shared_ptr <base_type> type_ptr;
union value_set{
	int _int;
	double _double;
	char _char;
	char * _str;
};//char * will free according the type of the value

typedef pair <type_ptr, value_set> key_value_tuple;
class record_type: public base_type{
public:
	vector <pair <string, type_ptr> > vt;
	void insert(const string & id, base_type);
	record_type(){
		type_id = RECORD_TYPE;
	}
};
class arr_type: public base_type{
public:
	arr_type(){
		type_id = ARR_TYPE;
	}
	bool checkindex(type_ptr type){

	}
	type_ptr index;
	type_ptr nxt;
private:
};
class continue_type:public base_type{
public:
	continue_type(){
		type_id = CONTINUE_TYPE;
	}
	key_value_tuple left;
	key_value_tuple right;
private:
};

class discrete_type:public base_type{
public:
	discrete_type(){
		type_id = DISCRETE_TYPE;
	}
	vector <string> index;
private:
};


inline string value_set_to_str(type_ptr ptr, value_set value){
	switch(ptr -> gettype()){
		case INT_TYPE:
			return string(itoa(value._int));
		case STR_TYPE:
			return string(value._str);
		case REAL_TYPE:
			return ftoa(value._double);
		case CHAR_TYPE:{
			string res = "";
			res += value._char;
			return res;
		}
	}
}
