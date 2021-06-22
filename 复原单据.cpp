#include<iostream>
using namespace std;
int main()
{
	const int n=10047;
	int cnt = 0;
	for(int i=1;i<99;i++)
	{
		int m;
		m = n + i*100;
		if(m%57==0||m%67==0) {
		    cout<<m<<endl;
		    cnt++;
		}
			
	}
	cout<<cnt<<endl;
}
