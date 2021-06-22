#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int p[1002];
int m[1002];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		for(int i=0;i<s.length();i++)
		{
			p[i] = s[i]- 78;
		}
		
		m[0] = p[0];
		int max=m[0];
		for(int i=1;i<s.length();i++)
		{
			if(m[i-1]>=0) m[i]=p[i]+m[i-1];
			else m[i]=p[i];
			if(m[i]>max) max = m[i];
		}    
		cout<<max<<endl;
		    
		    
	}
}
