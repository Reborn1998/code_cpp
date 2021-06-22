#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a=0,b=0;
    string s;
	while(cin>>s)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='a') a++;
			else b++;
		}
		cout<<a<<" "<<b<<endl;
	}
} 
