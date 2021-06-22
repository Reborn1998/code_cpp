#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    double sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int m;
			cin>>m;
		    sum += m;
		}
		cout<<setiosflags(ios::fixed) << setprecision(3) << sum/n << endl;	
	}	
} 
