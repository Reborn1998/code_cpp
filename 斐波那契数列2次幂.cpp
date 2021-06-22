#include<iostream>
using namespace std;
unsigned fib[400005];
void Fib(unsigned *f)
{
	f[0]=f[1]=1;
	for(int i=2;i<400001;i++)
	    f[i]=f[i-1]+f[i-2];
}
int main()
{
	int m,n;
	Fib(fib);
	while(cin>>m>>n)
	{
		unsigned k=1;
		if(m!=32)
		{
			k<<=m;
			cout<<fib[n]%k<<endl;
		}
		else cout<<fib[n]<<endl;
	}
}
