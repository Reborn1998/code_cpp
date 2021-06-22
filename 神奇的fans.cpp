#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		int *p=new int[m];
		for(int i=0;i<m;i++) cin>>p[i];
		sort(p,p+m);
		int c = p[1]-p[0];
		bool g=0;
		for(int i=2;i<m;i++)
		{
			if(p[i]-p[i-1]!=c){
				g=1;
				break;
			}
		}
		if(g) cout<<"no\n";
		else cout<<"yes\n";
	}
 } 
