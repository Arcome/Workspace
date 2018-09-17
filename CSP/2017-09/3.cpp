#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

class Jobject{
public:
	map<string, string> mstr;
	map<string, Jobject> mobj;
};

Jobject solve(Jobject jobj, string text){
	text.erase(0,1);
	text.erase(text.end()-1);
	
	int size = text.size();
	bool isKey = true;
	bool isValue = true;
	string key = "";
	string value = "";
	for(int i=0;i<size;i++){
		if(text[i]=='\"' && isKey){
			key = "";
			i++;
			while(text[i]!='\"'){
				if(text[i] == '\\'){
					i++;
					key += text[i];
					i++;
				}
				else{
					key += text[i];
					i++;
				}
			}
			continue;
		}
		if(text[i]==':'){
			isKey = false;
			isValue = true;
			continue;
		}
		if(text[i]=='{'){
			string inText = "";
			inText += text[i];
			i++;
			while(text[i]!='}'){
				inText += text[i];
				i++;
			}
			inText += text[i];
			Jobject inObj;
			inObj = solve(inObj, inText);
			jobj.mobj[key] = inObj;
		}
		if(text[i]=='\"' && isValue){
			value = "";
			i++;
			while(text[i]!='\"'){
				if(text[i] == '\\'){
					i++;
					value += text[i];
					i++;
				}
				else{
					value += text[i];
					i++;
				}
			}
			jobj.mstr[key] = value;
			continue;
		}
		if(text[i]==','){
			isKey = true;
			isValue = false;
			continue;
		}
	}
	return jobj;
}

void answer(Jobject jobj, string query){
	vector<string> subQuerys;
	bool hasDot = false;
	string subQuery = "";
	for(int i=0;i<query.size();i++){
		if(query[i]=='.'){
			subQuerys.push_back(subQuery);
			subQuery = "";
			hasDot = true;
		}
		else{
			subQuery += query[i];
		}
	}
	if(subQuery != ""){
		subQuerys.push_back(subQuery);
	}
	
	if(!hasDot){
		if(jobj.mstr.find(query) != jobj.mstr.end()){
			cout<<"STRING "<<jobj.mstr[query]<<endl;
		}
		else if(jobj.mobj.find(query) != jobj.mobj.end()){
			cout<<"OBJECT"<<endl;
		}
		else{
			cout<<"NOTEXIST"<<endl;
		}
	}
	else{
		Jobject inobj = jobj;
		for(int i=0;i<subQuerys.size();i++){
			subQuery = subQuerys[i];
			if(inobj.mstr.find(subQuery) != inobj.mstr.end()){
				cout<<"STRING "<<inobj.mstr[subQuery]<<endl;
			}
			else if(inobj.mobj.find(subQuery) != inobj.mobj.end()){
				inobj = inobj.mobj[subQuery];
			}
			else{
				cout<<"NOTEXIST"<<endl;
				break;
			}
		}
	}
	
}

int main(){
	freopen("in.txt","r",stdin);
	
	int n,m;
	cin>>n>>m;
	string text = "";
	string s;
	getline(cin, s);
	for(int i=0;i<n;i++){
		getline(cin, s);
		text+=s;
	}
	Jobject jobj;
	jobj = solve(jobj, text);
	string query;
	for(int i=0;i<m;i++){
		cin>>query;
		answer(jobj, query);
	}
	 
	return 0;
}
