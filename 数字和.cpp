#include<iostream> 
using namespace std;
int main(){
	long n;
	while(cin>>n){
		long a,b,s;
		a=n/10;
		s=n%10;
		while(a>=10){
		    b=a%10;	
		    a=a/10;
		    s=s+b; 
		} 
		cout<<s+a<<endl;
	}
}
