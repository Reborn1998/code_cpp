#include<bits/stdc++.h>
using namespace std;
const int maxn=222;
const int N=10010;
int n,m,k;
//int col[N];
//int H[maxn];
//int dp[N];
////map<int,int> mp;
//int main(){
//	scanf("%d%d",&n,&m);
//	int x;
//	memset(H,-1,sizeof(H));
////	memset(col,-1,sizeof(col));
////	memset(dp,1,sizeof(dp));
//	for(int i=0;i<m;i++){
//		scanf("%d",&x);
//		H[x] = i;
//	}
//	int k,num=0;
//	scanf("%d",&k);
//	for(int i=0;i<k;i++){		
//		scanf("%d",&x);
//		if(H[x]>=0){
//			col[num++] = H[x];
//		}
//	}
//	int ans=-1;
//	for(int i=0;i<num;i++){
//		dp[i]=1;
//		for(int j=0;j<i;j++){
//			if(col[j]<=col[i]&&dp[i]<dp[j]+1){
//				dp[i]=dp[j]+1;
//			}
//		}
//		ans = max(ans,dp[i]);
//	}
//	printf("%d\n",ans);
//}
int A[maxn],B[N],dp[maxn][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);
		dp[i][0] = 0;
	}
	scanf("%d",&k);
	for(int j=1;j<=k;j++){
		scanf("%d",&B[j]);
		dp[0][j] = 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(A[i]==B[j]){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1])+1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[m][k]);
}
