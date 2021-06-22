#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[100],b[100];
	int n,m,t,i,len1,len2;
	cin>>n;
	while(n--){
		cin>>m>>a>>b;
		len1=strlen(a);
		len2=strlen(b);
		for(i=0;i<len1;i++){
			if(a[i]!=b[i]) break;
		}
		t=m*(len2-i+len1-i);
		cout<<t<<endl;
	}
}
