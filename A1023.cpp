#include<bits/stdc++.h>
using namespace std;
int numA[50];
int numB[50];
string doubleA(string a){
	for(int i=0;i<a.size();i++){
		numA[i] = a[a.size()-1-i]-'0';
		numB[i] = numA[i]*2;
	}
	string b="";
	for(int i=0;i<a.size();i++){
		if(numB[i]>9){
			numB[i+1] += numB[i]/10;
			numB[i] = numB[i]%10;
		}
		b+= '0'+numB[i];
	}
	if(numB[a.size()]!=0 ) b+='0'+numB[a.size()];
//	cout<<"A:";
//	for(int i=0;i<a.size();i++){
//		cout<<numA[i]<<" ";
//	}
//	cout<<"\nB:";
//	for(int i=0;i<b.size();i++){
//		cout<<numB[i]<<" ";
//	}
	return b;
}
int main(){
	string a;
	cin>>a;
	string b;
	b = doubleA(a);
	if(a.size()!=b.size()){
		cout<<"No\n";
	}else{
		int n = a.size();
		sort(numA,numA+n);
		sort(numB,numB+n);
		int i=0;
		for(;i<n;i++){
			if(numA[i]!=numB[i]) {
				cout<<"No\n";
				break;
			}
		}
		if(i==n) cout<<"Yes\n";
	}
	reverse(b.begin(),b.end());
	cout<<b;
}
