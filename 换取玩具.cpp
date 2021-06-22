#include<iostream>
#include<string> 
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
    	int sum;
		int i,time;
        string a,b;
        cin>>time>>a>>b;
        for( i=0;i<a.length();i++)
        {
        	if(a[i]!=b[i])break;
		}

		cout<<time*(b.length()-i)+time*(a.length()-i)<<endl;
	}
}//=======================================
