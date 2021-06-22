#include<iostream>
using namespace std;
int main()
{
	int i;
	while(cin>>i)
	{
		if(i==0) break;
		if(i%3==0) cout<<"EVEN"<<endl;
		else cout<<"ODD"<<endl; 
	}
}
