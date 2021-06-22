#include<bits/stdc++.h>
using namespace std;
int n;
string x,y;

string toK(int &e,string str){
	int cnt=0;
	int flag = false;
	while(str[0]=='0'||str[0]=='.'){
		if(flag){
			cnt++;
		}
		if(str[0]=='.') flag = !flag;
		
		str.erase(str.begin());
	}
	if(str.size()==0) cnt=0;
	int pos = str.find('.');
	if(pos==-1) pos = str.size(); 
	string temp = "0.";
	int num=0;
	while(num<n){
        if(str[num]=='.') str.erase(str.begin()+num);
		if(str.size()>num ){
			temp += str[num];
		}
		if(num>=str.size()){
			temp += '0';
		}
		num++;
	}
	e = flag?-cnt:pos;
	return temp;
}
int main(){
	
	cin>>n>>x>>y;
	
	int e1=0,e2=0;
	string r1 = toK(e1,x);
	string r2 = toK(e2,y);
	if(r1==r2 && e1==e2){
		
		cout<<"YES "<<r1<<"*10^"<<e1<<endl;;
	}else{
		cout<<"NO "<<r1<<"*10^"<<e1<<" "<<r2<<"*10^"<<e2<<endl;
	}
}
