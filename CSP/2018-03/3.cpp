#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map> 
using namespace std;

class Rule{
public:
	Rule(string rule_="", string name_=""){
		rule = rule_;
		name_ = name;
	}
	string rule;
	string name;
};

bool isLetter(char c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z'); 
}

bool isDigit(char c){
	return c>='0'&&c<='9';
}

bool isMark(char c){
	return c=='-'||c=='_'||c=='.'; 
}

bool isInt(string p){
	bool isint = true;
	for(int i=0;i<p.size();i++){
		if(!isDigit(p[i])){
			isint = false;
			break;
		}
	}
//	return isint;
//	while(*p!='\0'){
//		if(!isDigit(*p)){
//			isint = false;
//			break;
//		}
//	}
//	return isint;
}

bool isStr(string p){
	bool isstr = true;
	for(int i=0;i<p.size();i++){
		if(!isLetter(p[i])){
			isstr = false;
			break;
		}
	}
//	while(*p!='\0'){
//		if(!isLetter(*p)){
//			isstr = false;
//			break;
//		}
//	}
	return isstr;
}

bool isValid(string s){
	bool isV = true;
	for(int i=0;i<s.size();i++){
		if(isLetter(s[i]) && isDigit(s[i]) && isMark(s[i]) ){
			continue;
		}
		else{
			isV = false;
			break;
		}
	}
	return isV;
}

string split(string& s, char csplit){
	int size = s.size();
	string ssplit;
	int index = 0;
	for(int i=0;i<size;i++){
		if(s[i]==csplit){
			if(ssplit!=""){
				index = i;
				break;
			}
		}
		else{
			ssplit += s[i];
		}
	}
	string t="";
	for(int i=index;i<size;i++){
		t += s[i];
	}
	s = t;
	return ssplit;
} 


int main(){
	freopen("in.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<Rule> rules(n);
	for(int i=0;i<n;i++){
		cin>>rules[i].rule>>rules[i].name;
	}
	
//	vector<string> urls(m);
	string url;
	for(int i=0;i<m;i++){
		cin>>url;
		if(!isValid(url)){
			cout<<"404"<<endl;
			continue;
		}
		
		string u = url;
//		char* purl = strtok(u, "/");
		string surl = split(u, '/');
		for(int i=0;i<n;i++){
			if(url == rules[i].rule){
				cout<<rules[i].name<<endl;
				break;
			}
			vector<string> parameters;
			string r = rules[i].rule;
//			char* prule = strtok(r,"/");
			string srule = split(r, '/');
			while(true){
				cout<<surl<<" "<<srule<<endl;
				if(surl=="" && srule==""){
					cout<<rules[i].name;
					for(int i=0;i<parameters.size();i++){
						cout<<" "<<parameters[i];
					}
					cout<<endl;
					break;
				}
				if(surl==""&&srule!="" || surl!=""&&srule==""){
					cout<<"404"<<endl;
					break;
				}
				if(surl==srule){
					surl = split(u, '/');
					srule = split(r, '/');
					continue;
				}
				if(srule=="<int>"&&isInt(surl)){
					parameters.push_back(surl);
					surl = split(u, '/');
					srule = split(r, '/');
					break;
				}
				if(srule=="<str>"&&isStr(surl)){
					parameters.push_back(surl);
					surl = split(u, '/');
					srule = split(r, '/');
					break;
				}
				if(srule=="<path>"){
					parameters.push_back(surl);
					u = "";
					r = "";
					break;
				}
			}
		}			
	}
	
	return 0;
}
