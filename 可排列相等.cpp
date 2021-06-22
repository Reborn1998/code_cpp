#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string n,m;
	while(getline(cin,n)&&getline(cin,m))
	{
		;
		if(!cin.get()) break;
		sort(n.begin(),n.end());
		sort(m.begin(),m.end());
		if(n==m) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
 } 
