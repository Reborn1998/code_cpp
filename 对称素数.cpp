#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,a,m,b,c,i;
	
	while(cin>>n){
		a=int(n/100);
		b=int(n/10)-10*a;
		c=n-100*a-10*b;
		m=c*100+b*10+a;
		if(n==m) {
			bool gg=1;
			for(i=2;(i*i<=m);i++)
			{
			if(n%i==0){gg=0;break;}							
		    }
		    if(gg==1)cout<<"Yes\n";
		    else cout<<"No\n";
	
	}else cout<<"No\n";
} 
}
/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,m,a,b,c,i;
	while(cin>>n){
		a=int(n/100);
		b=int(n/10)-10*a;
		c=n-100*a-10*b;
		m=c*100+b*10+a;
		if(n==m) {
			for(i=2;i<=sqrt(double(m));i++){
				if(n%i==0){cout<<"No"<<endl;break;}
			}
			if(n%i!=0) cout<<"Yes"<<endl;			
		}
		else cout<<"No"<<endl;
	}
} */

