#include<iostream>
#include<string>
using namespace std;
int main()
{

    char c;
    int n;
    while(cin>>c)
    {
        cin>>n;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n-i-1;j++) cout<<" ";
            for(int k=0;k<2*i+1;k++) cout<<c;
            cout<<endl;
        }
    }
} 
