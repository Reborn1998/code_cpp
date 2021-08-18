#include<bits/stdc++.h>
using namespace std;
int n,k,p;
vector<int>temp;
vector<int>ans;
vector<int>fac;
int Max=-1;

int power(int x){
	int a=1;
	for(int i=0;i<p;i++){
		a*=x;
	}
	return a;
}
void init(){
	for(int i=0;power(i)<=n;i++){
		fac.push_back(power(i));
	}
}
void DFS(int idx,int now,int sum,int facSum){	
	
	if(sum==n&&now==k){
		
		if(facSum>Max){
			ans = temp;
			Max = facSum;
		}
		return;
	}
	if(sum>n||now>k) return;
	if(idx-1>=0){
		temp.push_back(idx);
		DFS(idx,now+1,sum+fac[idx],facSum+idx);
		temp.pop_back();
		DFS(idx-1,now,sum,facSum);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(Max==-1) printf("Impossible");
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
}
