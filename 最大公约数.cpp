#include<iostream>
using namespace std;
int main(){
	unsigned int a,b,r;
	while(cin>>a>>b){
		while(r=a%b) {a=b,b=r;}
		cout<<b<<endl;
	}
	
}
