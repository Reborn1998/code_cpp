#include<iostream>
using namespace std;
int sum(int n)
{
	int sum=0;
	while(n)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		bool gg=1;
		for(int i=2;(i*i<=n);i++)
		{
			if(n%i==0){gg=0;break;}							
		}
		if(gg) cout<<sum(n)<<endl;
		    else cout<<0<<endl;
		
	}
}
