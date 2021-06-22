#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    while(getline(cin,a))
	{
	    int i;
        for( i=0;i<a.length();i++)
        {
            if(a[i]<'0'||a[i]>'9') {
            cout<<"No\n";
            break;
            }
        }
        if(i==a.length())
        {
            cout<<"Yes\n";
        }

    }  
}
