#include<iostream>
using namespace std;
char return_operator(int a,int b,int c)
{
	if(a+b==c) return '+';
	if(a-b==c) return '-';
	if(a*b==c) return '*';
	if(a/b==c) return '\\';
}
int main()
{
	int a,b,c;
	int n;
	cin>>n; 
	while(n--)
	{
		cin>>a>>b>>c;
		cout<<return_operator(a,b,c)<<endl;
	}
}
