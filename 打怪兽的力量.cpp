#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int p[10002];
int main()
{
	int t,A,B,C,D,E;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++) cin>>p[i];
		sort(p,p+n,cmp);
		cin>>A>>B>>C>>D>>E;
		A=A+B;
		int m;
		m = C/A;
		 
		for(int i=0;i<m;i++)
		{
			D += p[i]; 
		}
		if(D>=E) cout<<"Tyr is great!"<<endl;
		else cout<<"Tyr is not so great!"<<endl;
	}
} 
