#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	else 
		return a.length()<=b.length();
	
}

int main(){
	vector<string> s;

	for(string q;cin>>q;) {
	    string a;
		a = q;
		reverse(q.begin(),q.end());
		if(a==q){
			s.push_back(a);
		}
	}	

	sort(s.begin(),s.end(),cmp);

	for(int i=0;i<s.size();i++){
		cout<<s[i]<<endl;
	}
	
}
