#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int num[maxn];
int sum[maxn]={0};
int bsearch(int l,int r,int target){
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(sum[mid]<=target){
			l=mid+1;
		}else if(sum[mid]>target){
			r=mid;
		}
	}
	return l;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	int near=1000000010;
	for(int i=1;i<=n;i++){
		int idx = bsearch(i,n+1,m+sum[i-1]); 

		if(sum[idx-1]-sum[i-1]==m){
			near=m;
			break;
		}else if(idx<=n&&sum[idx]-sum[i-1]<near){
			near = sum[idx]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int idx = bsearch(i,n+1,near+sum[i-1]); 
		if(sum[idx-1]-sum[i-1]==near){
			printf("%d-%d\n",i,idx-1);
		}
	}
}
