#include<iostream>
#include<string>
using namespace std;
void coutss(const string&s1,int n)
{
	
	int m=s1.length();
	for(int i=0;i<n;i++)
	{
		cout<<s1[i%m];
	}
}
int main()
{
	string s="ST";
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++) cout<<" ";
			coutss(s,2*(n-i)-1);
			cout<<endl;
		}
	}
 } 
