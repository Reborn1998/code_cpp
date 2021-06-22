#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	char m[101][101];
	while(cin>>a>>b){
		int k=0;
		if(a==0&&b==0) break;
		for(int i=0;i<a;i++)
		    for(int j=0;j<b;j++)
		       cin>>m[i][j];
		for(int i=0;i<a;i++)
		    for(int j=0;j<b;j++){
		    	if(m[i][j]=='*') k++;
			}       
	    cout<<k<<endl; 
	}
	
}
