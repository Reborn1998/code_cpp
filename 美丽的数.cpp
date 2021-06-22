#include<iostream>
#include<string>
using namespace std;
int ss(int n)
{
	int a[10]={0};
	while(n){
		int m=n%10;
		a[m]++; 
		n /= 10;
	}
	int sum=0;
	if(a[2]) sum++;
	if(a[3]) sum++;
	if(a[5]) sum++;
	if(a[7]) sum++;
	return sum;
}
int main()
{
	int n;
	string s;
	while(cin>>n)
	{
		if(n==0) break;
		int *p=new int[n];
		cin>>p[0]; 
		int max=ss(p[0]),m=p[0];
		for(int i=1;i<n;i++)
		{
			cin>>p[i];
			if(ss(p[i])>max||(ss(p[i])==max&&p[i]<m)) {
				max = ss(p[i]);
				m = p[i];
			}
		}
		cout<<m<<endl;
	}
} 
