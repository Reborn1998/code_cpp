#include<iostream>
using namespace std;
bool is(int a,int b,int c)
{
	int d=(a*b)%c;
	return d%2;
	
}
int main()
{
	int m;
	cin>>m;
	int cnt=0;
	while(m--)
	{
		if(cnt++) cout<<endl<<endl;
		int a,b,n;
		cin>>a>>b>>n;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++)
			{
				if(is(i,j,n)) cout<<1;
				else cout<<0;
			}
			if(i<a)cout<<endl;
		}
	}
}
