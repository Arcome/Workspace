#include <iostream>
#include <string> 
using namespace std;

void printLine(string s){
	bool isEmPair = true;
	string link = "";
	string linkText = "";
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='_'){
			if(isEmPair){
				cout<<"<em>";
				isEmPair = false;
			}1
			else{
				cout<<"</em>";
				isEmPair = true;
			}
		}
		else if(s[i]=='['){
			i++;
			while(s[i]!=']'){
				linkText += s[i];
				i++;
			}
			i += 2;
			while(s[i]!=')'){
				link += s[i];
				i++;
			}
			cout<<"<a href=\""<<link<<"\">"<<linkText<<"</a>";
		}
		else{
			cout<<s[i];
		}
	}
}

void solve(string line, string& toPrint){
	if(line=="" && toPrint != ""){
		cout<<toPrint<<endl<<endl;
		toPrint = "";
		return ;
	}
	
	int size = line.size();
	
	// 标题
	if(line[0] == '#'){
		int numHead = 0;
		int numSpace = 0;
		int indexHead = 0;
		for(int i=0;i<size;i++){
			if(line[i]=='#'){
				numHead ++;
			}
			else{
				indexHead = i;
				break;
			}
		} 
		for(int i=indexHead;i<size;i++){
			if(line[i]==' '){
				numSpace ++;
			}
			else{
				break;
			}
		}
		string l = line.erase(0, numHead+numSpace);
		cout<<"<h"<<numHead<<">";
		printLine(l);
		string temp = "</h";
		temp += ('0'+numHead);
		temp += (">");
		toPrint = temp;
		return ;
	}
	
	//列表 
	if(line[0] == '*'){
		if(toPrint == ""){
			cout<<"<ul>"<<endl;
			toPrint = "</ul>";
		}
		int numSpace = 0;
		for(int i=1;i<size;i++){
			if(line[i]==' '){
				numSpace ++;
			}
			else{
				break;
			}
		}
		string l = line.erase(0, 1+numSpace);
		cout<<"<li>";
		printLine(l);
		cout<<"</li>"<<endl;
		return ;
	}
	
	//段落
	if(toPrint == ""){
		cout<<"<p>";
		toPrint = "</p>";
	} 
	else{
		cout<<endl;
	}
	printLine(line);
	return ;
}


int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	string line;
	string toPrint = "";
	while(getline(cin, line)){
		solve(line, toPrint);
	}
	if(toPrint != ""){
		cout<<toPrint<<endl;
	}
	
	return 0;
}
