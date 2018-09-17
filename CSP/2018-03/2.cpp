#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Ball{
public:
	Ball(int v_ = 1,int pos_ = 0){
		v = v_;
		pos_ = pos;
	}
	int v;
	int pos;
	int id;
};

bool sortPos(Ball b1, Ball b2){
	return b1.pos<b2.pos;
}

bool sortId(Ball b1, Ball b2){
	return b1.id<b2.id;
}

int main(){
	freopen("in.txt","r",stdin);
	int n,L,t;
	cin>>n>>L>>t;
	vector<Ball> balls(n,Ball());
	for(int i=0;i<n;i++){
		cin>>balls[i].pos;
		balls[i].id = i;
	}
	sort(balls.begin(), balls.end(), sortPos);
	
	if(balls[n-1].pos == L){
		balls[n-1].v = -1;
	}
	
	while(t--){
		for(int i=0;i<n;i++){
			if(balls[i].v == 1){
				balls[i].pos++;
			}
			else{
				balls[i].pos--;
			}
		}
		
		for(int i=1;i<n;i++){
			if(balls[i-1].pos == balls[i].pos){
				balls[i-1].v *= -1;
				balls[i].v *= -1;
			}
		}
		
		if(balls[0].pos == 0){
			balls[0].v *= -1;
		}
		if(balls[n-1].pos == L){
			balls[n-1].v *= -1;
		}
	}
	
	sort(balls.begin(), balls.end(), sortId);
	for(int i=0; i<n;i++){
		cout<<balls[i].pos<<" ";
	}
	cout<<endl;
	return 0;
}
