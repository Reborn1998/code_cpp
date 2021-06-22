#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(const string &s1,const string &s2){
	string a,b;
	a=s1.substr(0,3);
	b=s2.substr(0,3);
	if(a!=b) return a<=b;
	else {
		a=s1.substr(3,8);
	    b=s2.substr(3,8);
	    return a>=b;
	}
}
int main(){
	int N;
	cin>>N;
	string *p=new string[N];
	for(int i=0;i<N;i++){
		cin>>p[i];
	} 
	sort(p,p+N,cmp);
	for(int i=0;i<N;i++){
		cout<<p[i]<<endl;
	}
} 
