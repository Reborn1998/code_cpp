#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<=33;i++)
	{
		for(int j=0;j<=(100-3*i)/2;j++)
		{
			for(int k=0;k/3<=(100-3*i-2*j);k++)
			{
				if(i*3+j*2+k/3==100&&i+j+k==100&&k%3==0) cout<<i<<" "<<j<<" "<<k<<endl;
			}
		}
	}
 } 
