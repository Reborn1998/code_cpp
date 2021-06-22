#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int k,i,j=0;
	char ch=32;
	for(k=32;k<128;k=k+8){
	   for(i=0;i<8;i++){
	   	 if(ch==127)break;
	     cout<<setw(5)<<int(ch);
	     cout<<" "<<ch; 
	     ch=ch+1;
	     j=j+1;
	      if(j%8==0){
		   cout<<endl;
		   } 
		  else continue;
	    }
	}
}
