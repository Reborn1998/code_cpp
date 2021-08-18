#include<iostream>
using namespace std;
const int maxn=100010;
long long  numP[maxn]={0};
long long numT[maxn]={0};
int main(){
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i-1]=='P'){
			numP[i]=numP[i-1]+1;
		}
		else
			numP[i]=numP[i-1];
	}
	for(int i=s.size()-2;i>0;i--){
		if(s[i+1]=='T')
			numT[i] = numT[i+1]+1;
		else
			numT[i] = numT[i+1];
	}
	long long  sum = 0;
	for(int i=1;i<s.size();i++ ){
		if(s[i]=='A'){
			sum=(sum + numP[i]*numT[i])%1000000007;
		}
	}
	cout<<sum<<endl;
}
