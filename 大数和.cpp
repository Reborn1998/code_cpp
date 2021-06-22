#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string strAdd(const string& s1,const string& s2){
	string ss(s1);
	int i,flag=0;
	for(i=0;i<s2.length();i++){
		ss[i] = ss[i]+(s2[i]-'0')+flag;
		if(ss[i]>'9'){
			ss[i]-=10;
			flag =1;
		}
		else flag=0;		
	}
	for(;i<s1.length();i++){
		ss[i]=ss[i]+flag;
		if(ss[i]>'9') ss[i]-=10;
		else {
			flag=0;break;
		}		
	}
	if(flag) ss+='1';
	return ss;
}
bool cmp(const string& s1,const string& s2){
	int len1=s1.length(),len2=s2.length();
	return len1>=len2;
}
int main(){
	int n;
	while(cin>>n){
	    if(n==0) break;
    	vector<string> s;
    	string m;
    	for(int i=0;i<n;i++){
    		cin>>m;
    		s.push_back(m);
	    }
		for(int i=0;i<n;i++) reverse(s[i].begin(),s[i].end());
	    sort(s.begin(),s.end(),cmp);
	    

	    string x=s[0];
	    for(int i=1;i<n;i++){
	    	x=strAdd(x,s[i]);
	    }
	    reverse(x.begin(),x.end());
	    cout<<x<<endl;
	}
	
}
