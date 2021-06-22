#include<iostream>
using namespace std;
int main(){
 int x,y,m,n;
  while(cin>>n>>m)
  {  int flag=0;
    
  	if(m==1)
  	cout<<1<<endl;
  	if(m==2)
  	{
  		for(x=0;x<=n;x++)
  		for(y=0;y<=n/2;y++)
  		{
		  if(x+2*y==n)
  		   {
			 double c=x+y;
  		     double b=x,a; 
			 a=1;
  		     for(int i=0;i<x;i++)
			 {
			    a*=c;
			    a/=b;
			    c--;b--;
			 }
			 cout<<a<<"S0\n"; 
			    flag+=a;}
		  }
	  }
     cout<<flag<<endl;
  }
}
