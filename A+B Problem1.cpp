#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	char a1[1000],b1[1000],a2[1000],b2[1000];
	int T,len1,len2;
	cin>>T;
	while(T--){
		int c[1000]={0};
		int i,j,k,n,m;
		cin>>a1>>b1;
		len1=strlen(a1);		n=len1-1;for(i=0;i<len1;i++) a2[i]=a1[n--];
		len2=strlen(b1);		m=len2-1;for(i=0;i<len2;i++) b2[i]=b1[m--];	
		if(len1>=len2){
		
		for(i=0;i<len2;) 
		     if(a2[i]+b2[i]+c[i]<106) c[i]=a2[i]+b2[i]+c[i]-96,i++; 
		         else  {
		   	         c[i]=c[i]+a2[i]+b2[i]-106;c[++i]+=1;; 
		             }
		     
        for(i=len2;i<len1;i++) if(c[i]+a2[i]<58) c[i]=c[i]+a2[i]-48; else c[i]=a2[i]-48,c[++i]+=1;}	
        else{
		     for(i=0;i<len1;) 
		     if(a2[i]+b2[i]+c[i]<106) c[i]=a2[i]+b2[i]+c[i]-96,i++; 
		         else  {
		   	         c[i]=c[i]+a2[i]+b2[i]-106;c[++i]+=1; 
		             }
		     
        for(i=len1;i<len2;i++) if(c[i]+a2[i]<58) c[i]=c[i]+a2[i]-48; else c[i]=a2[i]-48,c[++i]+=1;}	
        
		cout<<a1<<" + "<<b1<<" = ";
		if(len1==len2) {
		for(i;i>=0;i--) cout<<c[i]; cout<<endl;}
		   else {
		   for(--i;i>=0;i--) cout<<c[i]; cout<<endl;}
	}
	
} 
