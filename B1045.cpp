#include<iostream>
#include<string>
using namespace std;
const int MOD = 1000000007;
int leftP[100001];
int main(){
	string str;
	cin>>str;
	int cnt = 0;
	for(int i=0;i<str.length();i++){
		leftP[i] = cnt;
		if(str[i]=='P') cnt++;
	}
	cnt=0;
	long long sum=0;
	for(int i=str.length()-1;i>0;i--){
		if(str[i]=='A') sum = (sum+cnt*leftP[i])%MOD;
		else if(str[i]=='T') cnt++;
	}
	cout<<sum;
}
