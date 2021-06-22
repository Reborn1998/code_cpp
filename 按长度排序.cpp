#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(const string s1,const string s2)
{
	return s1.length()<s2.length();
}
int main()
{
	int n;
	string s;
	
	while(cin>>n)
	{
	    vector<string> ss;
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			ss.push_back(s);
		}
		sort(ss.begin(),ss.end(),cmp);
		for(int i=0;i<n;i++) cout<<ss[i]<<endl;
		cout<<endl; 
		
	}
}
