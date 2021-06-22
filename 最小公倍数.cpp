#include<iostream>
using namespace std;
int main(){
	int a,b,c,r;
	while(cin>>a>>b){
		c=a*b;
		while(r=a%b){
			a=b;
			b=r;
		}
		cout<<c/b<<endl;
	}
} 
