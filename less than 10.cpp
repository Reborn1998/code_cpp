#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a+b>10)
		{
			cout<<"Refuse"<<endl;
			continue;
		}
		else
		{
			cout<<a+b<<endl;
		}
	}
}
