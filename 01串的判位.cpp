#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	unsigned int N,n,i;
    scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
        i=int(sqrt(1.0*(2*(n-1))));
        if(n==i*(i+1)/2+1){
        	printf("1\n");
        
		}
		else{
			printf("0\n");
        
		}
	    
		
	}
}

/* 	#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;       
int main(){
	unsigned a[65538] ;
    a[0]=1;
    for(int i=1;i<65538;i++) a[i]=i+a[i-1];
	
	
	int N,m,g;
    scanf("%d",&N);
	while(N--){
		g=0;
		scanf("%d",&m);
		int l=0;
		int r=65537;
		while(l<=r){
			if(m==a[(r+l)/2]) {g=1;break;}
			if(m<a[(l+r)/2]) r=(l+r)/2-1;
			else l=(l+r)/2+1;
			 
		}
		if(g) 
		 printf("%d\n",1);
	     else printf("%d\n",0);
	}
}
*/ 
