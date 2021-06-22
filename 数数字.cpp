#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	char c;
	while(cin>>s>>c)
	{
		int cnt=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==c) cnt++;
		}
		cout<<cnt<<endl;
	}
}
