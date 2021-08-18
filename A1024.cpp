#include<bits/stdc++.h>
using namespace std;
string s;
void add(string t){
	int flag = 0;
	for(int i=t.size()-1;i>=0;i--){
		s[i] = s[i]+t[i]+flag-'0';
		flag=0;
		if(s[i]>'9'){
			s[i] -= 10;
			flag = 1;
		}
	}
	if(flag) s = '1'+s;
}
int main(){
	int k,i;
	cin>>s>>k;
	for(i=0;i<k;i++){
		string t=s;
		reverse(t.begin(),t.end());
		if(s==t||i==k)break;
		add(t);
	}
	cout<<s<<endl<<i;
}
//int num1[1000];
//int num2[1000];
//int num[1000];
//int len;
//void init(string a){
//	len = a.size();
//	for(int i=0;i<a.size();i++){
//		num[i] = a[a.size()-i-1]-'0';
//	}
//}
//bool judge(){
//	for(int i=0;i<len;i++){
//		if(num1[i]!=num2[i]){
//			return false;
//		}
//	}
//	return true;
//}
//void change12(){
//	for(int i=0;i<len;i++){
//		num1[i] = num[i];
//		num2[i] = num[len-1-i];
//	}
////	cout<<"===============\n";
////	for(int i=0;i<len;i++)cout<<num1[len-i-1];
////	cout<<endl;
////	for(int i=0;i<len;i++)cout<<num2[len-i-1];
////	cout<<endl;
////	cout<<"======1111=====\n";
//}
//void add(){
//	for(int i=0;i<len;i++){
//		num[i] = num1[i]+num2[i];
//		if(num[i]>9){
//			num1[i+1] += num[i]/10;
//			num[i] = num[i]%10;
//		}
//	}
//	if(num1[len]!=0) num[len] = num1[len++];
//}
//int main(){
//	string a;
//	int k;
//	cin>>a>>k;
//	int cnt=1;
//	init(a);
//	for(;cnt<=k;cnt++){	
//		change12();
//		if(judge()){
//			for(int i=1;i<=len;i++){
//				cout<<num[len-i];
//			}
//			cout<<endl;
//			cout<<cnt-1;
//			return 0;
//		}
//		
//		add();
//	}
//	for(int i=1;i<=len;i++){
//		cout<<num[len-i];
//	}
//	cout<<endl;
//	cout<<k;
//}
