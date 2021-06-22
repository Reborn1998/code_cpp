#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;	
	while(cin>>s)
	{
	    int cnt[11]={0};
		for(int i=0;i<s.length();i++)
		{
			cnt[s[i]-'0']++;
		}
		for(int i=0;i<10;i++)
		{
			if(cnt[i]!=0) cout<<i<<" "<<cnt[i]<<endl;
		}cout<<endl; 
	}
} 
