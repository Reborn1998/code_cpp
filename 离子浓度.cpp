#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	string s;
	while (cin>>c>>s)
	{
		int cnt=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==c) cnt++; 
		} 
		 if(cnt>=s.length()/2.0) cout<<"Yes"<<endl;
		 else cout<<"No"<<endl;
	}
}
