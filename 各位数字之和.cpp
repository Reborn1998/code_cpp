#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[101];
	while(cin>>a){
		int len,m=0;
		len=strlen(a);;
		for(int i=0;i<len;i++)
		   m=m+a[i]-'0';
		cout<<m<<endl; 
	}
}
