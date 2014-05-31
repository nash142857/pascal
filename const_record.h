#pragma once
#include "common.h"
#include "type_value.h"
class const_record{
private:
	map <pair <string, string>, pair<type_ptr, value_set> >mp;
	string concat(const vector <string> & vt){
		string res = "";
		for(const string & s: vt){
			res += s + ":";
		}
		return res;
	}
public:
	bool insert(const string & id, 
		type_ptr type, 
		const vector <string> & scope, 
		value_set value){
		auto index = make_pair(id, concat(scope));
		if(mp.find(index) != mp.end())
			return false;
		mp[index] = make_pair(type,value);
		return true;
	}

	static shared_ptr <const_record> singleton(){
		static bool flag = false;
		static shared_ptr <const_record> res;
		if(!flag){
			res.reset(new const_record());
			flag = true;
			return res;
		}
		return res;
	}
	void debug(){
		for(auto i = mp.begin(); i != mp.end(); ++i){
			cout << i -> first.first << " " << i -> second.first -> gettype() 
			<< " " << value_set_to_str(i -> second.first, i -> second.second) << endl;
		}
	}
	bool exist_check(){
		
	}
};

