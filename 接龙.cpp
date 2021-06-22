#include<iostream>
#include<cstring>
using namespace std;
int main(){
     char a[16]={'n','A','2','3','4','5','6','7','8','9','1','0','J','Q','K','n'};
     char x[20],y[2];
     int len,m,n;
     while(cin>>x>>y){
     	len=strlen(x);
		 if((x[0]=='J'&&y[0]=='1')||(x[len-1]=='9'&&y[0]=='1'))  cout<<"Yes"<<endl;   	
     	   else {
			for(int i=0;i<16;i++){
     		         if(a[i]==x[0]) m=i;
     		         if(a[i]==x[len-1]) n=i;
		            }
           if((a[m-1]==y[0])||(a[n+1]==y[0])) cout<<"Yes"<<endl;
		      else cout<<"No"<<endl;}
	 }
}
