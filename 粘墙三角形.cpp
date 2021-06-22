#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		char ch='a'; 
		for(int i=0;i<n;i++)
		{
		    cout<<"a";
			for(int j=n-1-i;j>0;j--) cout<<" ";
			for(int j=0;j<=i;j++)  cout<<char(ch+j);
			cout<<endl;
		}
	}
} 
