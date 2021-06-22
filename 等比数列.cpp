#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double q,sum=0;
	while(cin>>n>>q)
	{
		sum = 1+q*(1-pow(q,n))/(1-q);
		
	    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl; 
	}
}
