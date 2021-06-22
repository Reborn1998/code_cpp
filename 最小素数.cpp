#include<iostream>
using namespace std;
 
int main()
{
	int a[3][3]={11,-1,17,41,-1,47,71,-1,79};
	int n;
	cin>>n ;
	while(n--)
	{
		char ch[2];
		cin>>ch;
		int i,j;
		i = (ch[0]-'A')%3;
		j = (ch[1]-'A')%3;
		cout<<a[i][j]<<endl;
	} 
}
