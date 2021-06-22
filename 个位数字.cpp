#include<iostream>
using namespace std;
int main()
{
	int a,b,n;
	cin>>n;
	while(n--)
	{
	    cin>>a>>b;
		int sum=1;
		for(int i=0;i<b;i++){
			sum=(sum%10)*(a%10);
		}
		sum=sum%10;
		cout<<sum<<endl;
		
	 } 
}
