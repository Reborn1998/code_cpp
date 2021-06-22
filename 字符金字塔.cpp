#include<iostream>
using namespace std;
int main()
{
    int n;
    
	while(cin>>n)
	{
		if(n==0) break;
		char c='A';
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n-1-i;j++) cout<<" ";
			for(int j=0;j<2*i+1;j++) cout<<c;
			cout<<endl;
			c = c + 1;
		}
		cout<<endl;
	}	
} 
