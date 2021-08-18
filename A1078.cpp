#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int table[11111];
int main(){
	int ms,n;
	scanf("%d %d",&ms,&n);
	int ts=ms;
	while(!isPrime(ts)) ts++;
	int a,idx;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		idx = a%ts;
		if(table[idx]==0) {
			printf("%d",idx);
			table[idx]=1;
		}
		else{
			int step=1;
			for(;step<ts;step++){
				idx = (a+step*step)%ts;
				if(table[idx]==0) {
					printf("%d",idx);
					table[idx]=1;
					break;
				}
			}
			if(step==ts)
			printf("-");
		}
		if(i!=n-1) printf(" ");
	}
}
