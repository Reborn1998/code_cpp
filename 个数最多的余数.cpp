#include<iostream>
using namespace std;
int main()
{
	int f[100]={0};
	int n,max=0;
	while(cin>>n)
	    f[n%100]++;
	for(int i=0;i<100;i++)
	{
		if(f[i]>max) max=f[i],n=i;
	}
	cout<<n<<endl;
 } 
