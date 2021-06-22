#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int m;
		m=n*n;
		cout<<n<<"^"<<3<<"=";
		if(m%2==1)
		{
			for(int i=0;i<n;i++)
			{
				cout<<m-(n/2-i)*2;
				if(i<n-1) cout<<"+";
			}
			cout<<endl;
		}
		else {
			m-=1;
			for(int i=1;i<=n;i++)
			{
				cout<<m-(n/2-i)*2;
				if(i<n) cout<<"+";
			}
			cout<<endl;
		}
	}
}
