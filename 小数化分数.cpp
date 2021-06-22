#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
	int r;
	while(r=a%b){
		a=b;
		b=r;
	}
	return b;
}
int main(){
	int N;
	cin>>N;
	string a;
	for(int i=0;i<N;i++){
		cin>>a;
		int m=a.length();
		int x=0,y=1;
		for(int i=2;i<m;i++){
			x=x*10+a[i]-'0';
			y *= 10;
			
			
		}
		
		int z = gcd(x,y);
		cout<<x/z<<"/"<<y/z<<endl;
	}
	
}
