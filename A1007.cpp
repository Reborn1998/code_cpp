#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int num[maxn];
int dp[maxn];
int s[maxn]={0};
int main(){
	int n;
	scanf("%d",&n);
	bool flag = true;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]>=0) flag = false;
	} 
	if(flag){
		printf("%d %d %d",0,num[0],num[n-1]);
		return 0;
	}
	dp[0] = num[0];
	for(int i=1;i<n;i++){
		if(dp[i-1]+num[i]>num[i]){
			s[i]=s[i-1];
			dp[i] = dp[i-1]+num[i];
		}else{
			s[i] = i;
			dp[i] = num[i];
		}
	} 
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k])
			k=i;
	}
	printf("%d %d %d",dp[k],num[s[k]],num[k]);
} 
