#pragma once
#include "type_value.h"
class var_record{
private:
	map < pair<string, string>, shared_ptr <base_type> > mp;
	vector < pair <string, shared_ptr <base_type> > > vt;
	string concat(const vector <string> & vt){
		string res = "";
		for(const string & s: vt){
			res += s + ":";
		}
		return res;
	}
public:
	bool insert(const string type_id, shared_ptr <base_type> type, vector <string> s = {}){
		string scope = concat(s);
		if(mp.find(make_pair(type_id, scope)) != mp.end())
			return false;
		mp[make_pair(type_id, scope)] = type;
		vt.push_back(make_pair(type_id, type));
		return true;
	}
	static shared_ptr <var_record> single(){
		static shared_ptr <var_record> res;
		static bool flag = false;
		if(!flag){
			res.reset(new var_record());
			flag = true;
			return res;
		}
		else{
			return res;
		}
	}
	void debug(){
		
	}
	pair <int,int> searchoffset(const string & id){
		int off = 0;
		for(int i = 0; i < vt.size(); ++i){
			if(vt[i].first != id)
				off += vt[i].second -> getsize();
			else{
				return make_pair(off, vt[i].second -> gettype());
			}
		}
		return make_pair(-1, -1);
	}
	pair <int, int> searchoffset(const string & id, int index){
		int off = 0;
		for(int i = 0; i < vt.size(); ++i){
			if(vt[i].first != id)
				off += vt[i].second -> getsize();
			else{
				if(vt[i].second -> gettype() == ARR_TYPE){
					arr_type * tmp = (arr_type *)vt[i].second.get();
					off += tmp -> nxt -> getsize() * index;
					return make_pair(off, tmp -> nxt -> gettype());
				}
				else
					return make_pair(-1,-1);
			}
		}
		return make_pair(-1,-1);
	}
	pair <int, int> searchoffset(const string & id, const string & member){
		int off = 0;
		for(int i = 0; i < vt.size(); ++i){
			if(vt[i].first != id)
				off += vt[i].second -> getsize();
			else{
				if(vt[i].second -> gettype() == RECORD_TYPE){
					record_type * tmp = (record_type *)vt[i].second.get();
					auto off2 = tmp -> search(member);
					if(off2.first == -1)
						return make_pair(-1,-1);
					return make_pair(off + off2.first, off2.second);
				}
			}
		}
		return make_pair(-1,-1);
	}
	void gencode(){
		int off = 0;
		for(int i = 0; i < vt.size(); ++i){
			off += vt[i].second -> getsize();
		}
		cout << "SUBI $SP, $SP, " + itoa(off) << endl;
	}
};