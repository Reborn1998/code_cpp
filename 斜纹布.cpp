#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int n,x;
	while(cin>>s)
	{
		cin>>n;
		int cnt = 0,m = 0;
		
		for(int i=0;i<n*n;i++)
		{
			cnt++;
			if(cnt%n==2)  x=m;
			cout<<s[m++];
			if(cnt%n==0) cout<<endl,m=x;
			if(m==s.size()) m=0;
			
		}
	}
 } 
