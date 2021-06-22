#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int toi(int n)
{
	int sum=0;
	while(n)
	{
		sum = sum*10 + n%10;
		n /= 10;
	}
	return sum;
}
bool cmp( int x,int y)
{
	int a,b;
	a = toi(x);
	b = toi(y);
	return a<b;
}
int main()
{
	int N;
	cin>>N;
	int num[88];
	while(N--)
	{
		int n;
		cin>>n;
	    for(int i=0;i<n;i++)
	    {
	    	cin>>num[i];
		}
		sort(num,num+n,cmp);
		for(int i=0;i<n-1;i++)
		    cout<<num[i]<<" ";
		cout<<num[n-1]<<endl;
	}
}
