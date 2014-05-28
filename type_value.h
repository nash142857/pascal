#pragma once
#include "common.h"

class base_type{
protected:
	int type_id;//0 for int 1 for real 2 for char 3 for char *
			//4 for record 5 for array.
public:
	void set_type(const int i){
		type_id = i;
	}
	int gettype(){
		return type_id;
	}
};
class record_type: public base_type{
	vector <string, shared_ptr <base_type> > vt;
	void insert(const string & id, base_type);
	record_type(){
		type_id = 4;
	}
};
class arr_type: public base_type{
	int number;
	shared_ptr <base_type> nxt;
	arr_type(){
		type_id = 5;
	}
};

union value_set{
	int _int;
	double _double;
	char _char;
	char * str;
};//char * will free according the type of the value
