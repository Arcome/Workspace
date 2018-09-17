#include <iostream>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int step;
	int point = 0;
	int jumpPoint = 0;
	while(cin>>step){
		if(step == 0){
			break;
		}
		if(step == 1){
			point++;
			jumpPoint = 0;
		}
		if(step == 2){
			jumpPoint += 2;
			point += jumpPoint;
		}
	}
	cout<<point<<endl;
	return 0;
}
