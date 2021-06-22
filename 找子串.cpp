#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a)
    {   
	    int i; 
        cin>>b;
        for(i=0;i<a.length()-b.length();i++)
        {
            string c;
            c=a.substr(i,b.length());
            if(c==b) {
                cout<<"Yes\n";break;
            }

        }
        if(i==a.length()-b.length()) cout<<"No\n";
    }
}
