#include<iostream>
using namespace std;
bool pd(int a,int b,int c)
{
	int x=a-b;
	if(x<0) x=-x;
	if(a+b>c && x<c) return 1;
	else return 0;
}
int main()
{
	int n;
	int a,b,c;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		if(a==0 || b==0 || c==0) 
		{
		    cout<<"NO"<<endl;
		    continue;
		} 
		if(pd(a,b,c)&&pd(a,c,b)&&pd(b,c,a))    cout<<"YES\n";
		else cout<<"NO\n";
	}
} 
