#include<iostream>
#include<string>
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
void fb(string *f){
	f[1]=f[2]="1";
	for(int i=3;i<1002;i++){
		
	
		f[i]=strAdd(f[i-1],f[i-2]);
		reverse(f[i-2].begin(),f[i-2].end());		
	}
		
}
int main(){
	int n;
	string f[1003];
	
	fb(f);
	reverse(f[999].begin(),f[999].end());
	reverse(f[1000].begin(),f[1000].end());
	cin>>n;
	int pi;
	while(n--){
		cin>>pi; 
		cout<<f[pi]<<endl;

	} 
} 
/*string f[1001]= {"0","1"};
const int bitnum = 100;
string add(string x,string y){
	string ans;
	int lenx = x.length();
	int leny = y.length();
	if(lenx<leny){
		for(int i=1;i<=leny-lenx;i++)
		    x = '0' + x;
	}
	else{
		for(int i=1;i<=lenx-leny;i++)
		    y = '0' + y;
	}
	int cf=0;
	int temp;
	for(int i=lenx-1;i>=0;i--){
		temp = x[i]-'0'+y[i]-'0'+cf;
		cf = temp/10;
		temp%=10;
		ans = char('0'+temp) + ans;
	}
	if(cf!=0){
		ans = char(cf+'0') + ans;
	}
	return ans;
}
int main(){
	for(int j=2;j<=1000;j++)
	    f[j] = add(f[j-1],f[j-2]);
	    int n;
	    cin >> n;
	    for(int i=1;i<=n;i++){
	    	int m;
	    	cin>>m;
	    	cout<<f[m]<<endl;
		}
}*/



