#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
	char c;
	int Sum=0;
	while(isdigit(c=getchar())){
		Sum += c-'0';
	}
	string temp = to_string(Sum);
	for(int i=0;i<temp.size();i++){
		if(i>0) cout<<" ";
		cout<<s[temp[i]-'0'];
	}
} 
