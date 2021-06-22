#include<iostream>
using namespace std;
int main(){
	long m;
	while(cin>>m){
		int k=0;
	   if(m==0) break; 
       while(m){
       	if(m&0x0001) k++;
       	    m=m>>1;
       	    
	    } 
        cout<<k<<endl;
	 }
}
