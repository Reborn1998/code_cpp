#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(s[0]=='-') reverse(s.begin()+1,s.end());
		else reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
}
