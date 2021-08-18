#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long sum=1;
	int ansL=0,ans;
	int tempL=0,temp;
	scanf("%lld",&n);
	for(int i=2;i*i<=n;i++){
		int j=i;
		while(n%j==0){
			sum*=j;
			if(sum>n||n%sum!=0) break;
			if(j-i+1>ansL){
				ansL=j-i+1;
				ans=i;
			}
			j++;
			
		}
		sum=1;

		
		
	}
	if(ansL==0) printf("1\n%lld",n);
	else{
		printf("%d\n",ansL);
		for(int i=0;i<ansL;i++){
			printf("%d",ans++);
			if(i!=ansL-1) printf("*");
		}
	}
}
