#include<iostream>
using namespace std;
int main(){
	int a[11][11];
	int n,m,i,j;
	cin>>n;
	while(n--){
		cin>>m;
		for(i=0;i<m;i++)
		   for(j=0;j<m;j++)
		     cin>>a[i][j];
		if(m==1){cout<<"yes"<<endl;continue;}     
		for(i=0;i<m;i++){
		      for(j=0;j<m/2;j++){
		      	if(a[i][j]!=a[i][m-1-j]) {cout<<"no"<<endl;break;} 
		      }
		      if(a[i][j]!=a[i][m-1-j]) break;
		} 
		if(i!=m) continue;
		for( i=0;i<m/2;i++){
		      for(j=0;j<m;j++){
		      	if(a[j][i]!=a[m-1-j][i]) {cout<<"no"<<endl;break;}
		      }
			  if(a[j][i]!=a[m-1-j][i]) break;		      
		}
		if(j==m) cout<<"yes"<<endl;		
	}
}
