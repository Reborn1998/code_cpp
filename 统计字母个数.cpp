#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[26]={0};
	char ch;
	while((ch=getchar())!='#'){
		for(int i=0;i<26;i++)
		if(i==int(ch-'a')) a[i]+=1;
	}
	for(int i=0;i<26;i++) cout<<char(i+'a')<<" "<<a[i]<<endl;
} 
