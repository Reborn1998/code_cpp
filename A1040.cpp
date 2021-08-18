#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string s;
int dp[maxn][maxn];
int main(){
	getline(cin,s);
	int len = s.size(),ans=1;
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int i=3;i<=len;i++){
		cout<<i<<endl;
		for(int j=0;j+i-1<len;j++){
			if(s[j]==s[j+i-1]&&dp[j+1][j+i-1-1]==1){
				dp[j][j+i-1]=1;
				ans = i;
			}
		}
	}
	printf("%d\n",ans);
}
