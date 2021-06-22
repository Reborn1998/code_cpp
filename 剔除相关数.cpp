#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string s1,string s2)
{
	
	if(s1.length()==s2.length()) return s1<s2;
	else return s1.size()<s2.size();
}
void del(string *p,int &m)
{
	
	int cnt = 0;
	for(int i=0;i<m-1;)
	{
		string a,b;
		
		a = p[i];
		b = p[i+1];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		 
		if(a == b){
			for(int j=i;j<m-1;j++) {
			    p[j] = p[j+1];
			    
			}
			m--;
			cnt = 1;
			
			
		}
		else {
			
			if(cnt) {
				for(int j=i;j<m-1;j++) p[j] = p[j+1];m--;cnt = 0;
				
			}
			else i++;
			
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		
		string *s = new string[n];
		for(int i=0;i<n;i++) cin>>s[i];
		if(n==1){
			cout<<s[0]<<endl;
			continue; 
		}
		sort(s,s+n,cmp);
		del(s,n);
		if(n==1) {
		    cout<<"None";
		    n--;
		}
		for(int i=0;i<n;i++) cout<<s[i]<<" ";
		cout<<endl;
		delete[] s;
	}
	
}
