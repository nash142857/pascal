#pragma once
#include "common.h"
#define RECORD_TYPE 142857
#define ARR_TYPE 428571
class base_type{
protected:
	int type_id;//0 for int 1 for real 2 for char 3 for char *
			//4 for record 5 for array.
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
class record_type: public base_type{
	vector <pair <string, type_ptr> > vt;
	void insert(const string & id, base_type);
	record_type(){
		type_id = RECORD_TYPE;
	}
};
class arr_type: public base_type{
	int number;
	shared_ptr <base_type> nxt;
	arr_type(){
		type_id = ARR_TYPE;
	}
};

union value_set{
	int _int;
	double _double;
	char _char;
	char * str;
};//char * will free according the type of the value

typedef pair <type_ptr, value_set> key_value_tuple;

