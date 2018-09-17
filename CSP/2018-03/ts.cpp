#include <iostream> 　　
#include <cstring> 　　
using namespace std;

string split(string s, char csplit){
	int size = s.size();
	string ssplit;
	for(int i=0;i<size;i++){
		if(s[i]==csplit){
			if(ssplit!=""){
				break;
			}
		}
		else{
			ssplit += s[i];
		}
	}
	return ssplit;
} 

bool isInt(char* p){
	bool isint = true;
	while(*p!='\0'){
		if(!isDigit(*p)){
			isint = false;
			break;
		}
	}
	return isint;
}

int main()
{
//	char sentence[]="This is a sentence with 7 tokens"; 
//	char*p = sentence;
//	while(*p!='\0'){
//		cout<<*p<<"*";
//		p++;
//	}
	
//	string s = "/ddd/aaa/bbb/";
//	string a = split(s,'/');
//	cout<<a<<endl;

	string b = "123";
	cout<<isInt(b)<<endl;

//	cout<<"The string to be tokenized is:\n"<<sentence<<"\n\nThe tokens are:\n\n";
//
//	char *tokenPtr=strtok(sentence," ");
//	cout<<sentence<<endl;
//
//	while(tokenPtr!=NULL) {
////		if(strcmp(tokenPtr,"This")==0){
////			cout<<"ok"<<endl;
////		}
//		cout<<tokenPtr<<endl;
//		tokenPtr=strtok(NULL," ");
//	}

//	cout<<"After strtok, sentence = "<<sentence<<endl;
	return 0;
}

