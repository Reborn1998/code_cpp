#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	double a;
	cin>>n;
	while(n--)
	{
		cin>>a; 
		int m=int(a);
		if(m==a) cout<<m<<endl;
		else cout<<m+1<<endl;
	}
}
