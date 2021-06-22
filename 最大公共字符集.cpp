#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1,s2;
	string s3;
	while(cin>>s1>>s2)
	{
		s3.clear();
		for(int i=0;i<s1.length();i++)
		{
			for(int j=0;j<s2.length();j++)
			{
				if(s1[i]==s2[j]) s3+=s1[i];
			}
		}
		sort(s3.begin(),s3.end());
		if(s3[0]) cout<<s3<<endl;
		else cout<<"NULL\n";
	}
} 
