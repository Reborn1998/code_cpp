#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std;
bool cmp( string s1, string s2)
{
	if(s1.length()!=s2.length()) return s1.length()<s2.length();  // �ַ����̵���ǰ�� 
	else 
	{
		string a=s1,b=s2;
	    sort(s1.begin(),s1.end());     // ����������ڱȽ�1������ 
		sort(s2.begin(),s2.end());
		if(s1==s2)    return a<b;    // ����1������ͬ�Ƚ�ACSII 
		else return s1<s2;          //  �Ƚ�����1������ 
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
