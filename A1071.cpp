#include<bits/stdc++.h>
using namespace std;
bool check(char c){
	if(c>='0'&&c<='9') return true;
	if(c>='A'&&c<='Z') return true;
	if(c>='a'&&c<='z') return true;
	return false;
}
int main(){
	map<string,int> count;
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.size()){
		string word;
		while(i<str.size()&&check(str[i])){
			if(str[i]>='A'&&str[i]<='Z'){
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word!=""){
			if(count.find(word)==count.end()) count[word] = 1;
			else count[word]++;
		}
		while(i<str.size()&&!check(str[i])){
			i++;
		}
	}
	string ans;
	int Max=0;
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>Max){
			ans = it->first;
			Max = it->second; 
		}
	}
	cout<<ans<<" "<<Max;
} 
