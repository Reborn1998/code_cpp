#include<iostream>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,sum=0;
		cin>>n;
		int *p = new int[n];
		for(int i=0;i<n;i++) 
		{
			cin>>p[i];
		}
		sort(p,p+n,cmp);
		for(int i=0;i<10;i++) sum+=p[i];
		cout<<sum<<endl;
	}
}
