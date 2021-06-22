#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std;
bool cmp( string s1, string s2)
{
	if(s1.length()!=s2.length()) return s1.length()<s2.length();  // 字符串短的排前面 
	else 
	{
		string a=s1,b=s2;
	    sort(s1.begin(),s1.end());     // 数组排序便于比较1的数量 
		sort(s2.begin(),s2.end());
		if(s1==s2)    return a<b;    // 数字1数量相同比较ACSII 
		else return s1<s2;          //  比较数字1的数量 
	}
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
