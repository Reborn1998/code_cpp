#include<iostream>
#include<iostream>
using namespace std;
int h[302],q[302];
void hc(int *p){
	p[1]=6;
	for(int i=2;i<301;i++){
		p[i]=p[i-1]+i*(i+1)*(i+2);
	}
}
void qw(int *p){
	for(int i=5;i<300;i++){
		p[i]=(i-4)*(i-4);
	}
}

}
int main(){
	hc(h);
	qw(q);
	int n;
	while(cin>>n){
		int cc=0;
		int s;
		s=h[n]-q[n]*100;
		cout<<s<<endl;
	}
	
} 
