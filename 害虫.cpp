#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int p[302];
int q[302];
void H(int *p){
	p[1]=6;
	for(int i=2;i<301;i++){
		p[i]=p[i-1]+i*(i+1)*(i+2);
	}
}
void Q(int *q){
	q[1]=q[2]=q[3]=q[4]=0;
	for(int i=5;i<300;i++){
		q[i]=i*i-q[i-1];
	}
}
int main(){
	H(p);
	Q(q);
	int n;
	while(cin>>n){
		int s=0,c=0;
cout<<p[5];
		for(int j=1;j<n;j++)
		{
			c=c+p[j]*pow(100,n+1-j);
		}
		
		s=p[n]-c;
		cout<<s<<endl;
		
	} 
	
}
