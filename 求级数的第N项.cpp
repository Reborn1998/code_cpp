#include<iostream>
using namespace std;
int f[10003];
void  fun(int *f)
{
	f[1]=0;
	f[2]=2;
	for(int i=3;i<10002;i++)
	{
		f[i]=3*f[i-1]+5*f[i-2];
	}
	
}
int main()
{
	fun(f);
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		cout<<f[n]<<endl;
	}
}
