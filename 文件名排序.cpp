#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std; 
bool cmp(const string& s,const string& t){
	size_t ls=s.length(),lt=t.length();
	size_t len=(ls<lt?ls:lt);
	for(int i=0;i<len;i++){
		if(tolower(s[i])!=tolower(t[i])){
			return tolower(s[i])<tolower(t[i]); 
		}
	}
	return ls<=lt;
}
int main(){
	vector<string> s1;
	vector<string> s2;
	for(string a,b;cin>>a>>b;){
		if(b=="Dir") s1.push_back(a);
		else s2.push_back(a);
	}
	sort(s1.begin(),s1.end(),cmp);
	sort(s2.begin(),s2.end(),cmp);
	for(int i=0;i<s1.size();i++){
		cout<<s1[i]<<" Dir\n";
	}
	for(int i=0;i<s2.size();i++){
		cout<<s2[i]<<" File\n";
	}
}
