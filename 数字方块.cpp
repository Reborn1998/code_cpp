#include<iostream>
#include<string>
using namespace std;
int main()
{
    char n;
    while(cin>>n){
        if(n=='0') break;
        for(int i=0;i<n-'0';i++) cout<<string(n-'0',n)<<endl ;
        cout<<endl;
    }
}

