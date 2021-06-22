#include<iostream>
using namespace std;
int main()
{
	char c;
	cin>>c;
	for(int i=0;i<7;i++)
	{
		for(int j=6-i;j>0;j--) cout<<" ";
		for(int k=0;k<2*i+1;k++) cout<<c;
		cout<<endl;
	}
 } 
