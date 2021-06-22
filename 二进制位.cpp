#include<iostream>
using namespace std;
int main(){
	int d;
	cin>>d;
	int n;
	while(cin>>n){
	    int k=0;
		while(n){
			int flag = 0;
       	     if(n&0x0001) {
				cout<<k;
				flag=1;
			}
			k++;
       	    n=n>>1;
			if(n>0&&flag) cout<<" ";
		    if(n==0) cout<<endl;    	    
	    } 
	}
}
