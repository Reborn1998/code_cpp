#include<iostream>
using namespace std;
int main()
{
	char c;
	int n;
	while(cin>>c)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=n-1-i;j>0;j--) cout<<" ";
			for(int k=0;k<i+1;k++) cout<<c;
			cout<<" ";
			for(int k=0;k<i+1;k++) cout<<c;
			cout<<endl;
		}
	}
}
