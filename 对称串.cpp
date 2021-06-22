#include<iostream>
#include<string> 
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const string&s1,const string&s2)
{
	return s1.length()<s2.length();
}
int main()
{
	vector<string> ss;
	string s;
	while(cin>>s)
	{
		string n;
		n=s;
		reverse(s.begin(),s.end());
		if(n==s) ss.push_back(n);
	}
	sort(ss.begin(),ss.end(),cmp);
	for(int i=0;i<ss.size();i++)
	{
		cout<<ss[i]<<endl;
	}
}
