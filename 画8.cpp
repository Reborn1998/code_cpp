#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int cnt = 0; 
	while(n--)
	{
		if(cnt++) cout<<endl;
		char c;
		int m,M,i;
		cin>>c>>m;
		M=m;
		if(m%2!=0) {  m++; }
	
		for(i=0;i<m/2;i++)
		{
			if(i==0||i==m/2-1) cout<<string(M/6+1,' ')<<string(M/2-1,c);
			else cout<<string(M/6+1,c)<<string(M/2-1,' ')<<string(M/6+1,c);
			cout<<endl;
		}
		for( i;i<M;i++){
		    if(i==M-1) cout<<string(M/6+1,' ')<<string(M/2-1,c);
		    else cout<<string(M/6+1,c)<<string(M/2-1,' ')<<string(M/6+1,c);
		    cout<<endl;
		}
			
	}
}
