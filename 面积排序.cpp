#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	void select_sort(x[],y[],s[]);
	int i,j,k,n=0;
    i=0;
	while(cin>>x[i]>>y[i]>>x[i+1]>>y[i+1]){
    	s[i]=abs((x[i]-x[i+1])*(y[i]-y[i+1]));
    	i++;
    	n++;
	}
	for(j=1;j<n;j++){
		for(i=0;i<=n-1-j;i++){
		  if(s[i]>s[i+1]){
		k=s[i];s[i]=s[i+1];s[i+1]=k;	
		  }
		}
	} 
    for(i=0;i<n;i++) cout<<s[i]<<endl;
} 
