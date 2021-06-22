#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch;
	int n,m;
	int cnt=0;
	while(cin>>ch>>n>>m)
	{
		if(cnt++) cout<<endl;
		if(n==0&&m==0) break;
		for(int i=0;i<2*n+m;i++)
		{
			cout<<"B";
			if(i<n||i>=m+n)
			{
				
					for(int k=0;k<n;k++)
					{
						cout<<" ";
					}
					for(int k=0;k<m;k++)
					{
						cout<<ch;
					}
					cout<<endl;
				
				
			}
			else{
				
					for(int k=0;k<n;k++)
					{
						cout<<ch;
					}
					for(int k=0;k<m;k++)
					{
						cout<<" ";
					}
					
					for(int k=0;k<n;k++)
					{
						cout<<ch;
					}
					cout<<endl;
				
			}
		}
	}
}
