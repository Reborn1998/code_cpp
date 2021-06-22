#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std;
bool cmp( string s1, string s2)
{
	int x=0,y=0;
	for(int i=0;i<s1.size();i++) if(s1[i]=='1') x++;    //数1的个数 
	for(int i=0;i<s2.size();i++) if(s2[i]=='1') y++;
	return x<y; 
}
int main()
{
	vector<string> ss;
	for(string s;cin>>s;)
	{
		
		ss.push_back(s);
	}
	sort(ss.begin(),ss.end(),cmp);
	for(int i;i<ss.size();i++)
	{
		cout<<ss[i]<<endl;
	}
}
