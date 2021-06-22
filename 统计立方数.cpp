#include<iostream>
#include<cmath>
using namespace std;
double s[2000];
void fun(double *s)
{
	for(int i=1;i<=1652;++i)
	{
		s[i] = i*i*i;
	}
}
int main()
{
	double a;
	int cnt=0;
	fun(s);
	while(cin>>a)
	{
		if(a==0) break;
		 
		for(int i=1;i<=1652;i++)
		{
			if(s[i]==a) cnt++;
		}
		 
	}
	cout<<cnt<<endl;
}
