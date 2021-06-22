#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	char a[1004];
	while(cin>>a){
	    int len,n=0,m=0;
	    int x;
		len=strlen(a);
		for(int i=0;i<len;i+=2) n+=a[i]-'0';
		for(int i=1;i<len;i+=2) m+=a[i]-'0';
		x=n-m;
		if(x<0) x=-x;
		if(x%11==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		 
	}
}
