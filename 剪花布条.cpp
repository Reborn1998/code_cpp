#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1)
	{
		if(s1=="#") break;
		else cin>>s2;
		int len1 = s1.length();
		int len2 = s2.size();
		int cnt = 0;
		for(int i=0;i<=len1-len2;)
		{
			string s;
			s = s1.substr(i,len2);
			if(s==s2){ cnt++; i += len2;}
		    else i++;
		}
		cout<<cnt<<endl;
	}
}
