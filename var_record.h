class var_record{
private:
	map < pair<string, string>, shared_ptr <base_type> > mp;
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
};