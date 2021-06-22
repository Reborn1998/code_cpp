#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		int *p = new int [n];
		int cnt=0;
		for(int i=0;i<n;i++) cin>>p[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(p[i]>p[j]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}
