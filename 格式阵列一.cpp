#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,M=0;
	while(cin>>n)
	{
		if(M++) cout<<endl;
	    int cnt=0;
		for(int i=0;i<n;i++)
		{
		    if(i>0)cout<<endl;
			cout<<setw(2)<<i+1<<"  ";
			cnt=i;
			for(int j=i;j<i+n;j++) 
			{
				
				if(cnt<n) cout<<setw(3)<<cnt;
				else
				{
				    cnt%=n;
					cout<<setw(3)<<cnt; 
				}
				cnt++;
			}
			
		}
		cout<<endl;
	}
 } 
