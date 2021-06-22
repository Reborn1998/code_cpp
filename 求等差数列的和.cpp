#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0) break; 
		int sum;
		sum=(a+b)*(((b-a)/c)+1)/2;
		/*for(int i=a;i<=b;i+=c)
		    sum+=i;*/
	    cout<<sum<<endl;
	}
 } 
