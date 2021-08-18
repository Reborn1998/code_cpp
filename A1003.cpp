#include<bits/stdc++.h>
using namespace std;
const int maxn = 555;
int n,m,c1,c2;
int G[maxn][maxn]={0};
int vis[maxn];
int cp[maxn];
int minw=0x7fffffff,cnt=0,maxNun=0;
void DFS(int start,int weight,int num){
	if(weight>minw) return;
	if(start==c2){
//		cout<<"?"; 
		if(weight<minw){
			cnt=1;
			maxNun=num;
			minw=weight;
		}else if(weight==minw){
			cnt++;
			if(num>maxNun) maxNun=num;
		}
		return;
	}
	vis[start] = weight;
	for(int i=0;i<n;i++){
		if(G[start][i]>0){
			if(vis[i]>weight+G[start][i]){
//				cout<<"!!"<<i<<endl;
				int temp = vis[i];
				vis[i] = weight+G[start][i];
				DFS(i,weight+G[start][i],num+cp[i]);
				vis[i] = temp;
			}
		}
	}
}
void init(){
	for(int i=0;i<n;i++){
		vis[i] = 0x7fffffff;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&cp[i]);
	}
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		G[a][b] = G[b][a] = w;
	}
	init();
	DFS(c1,0,cp[c1]);
	printf("%d %d",cnt,maxNun);
} 
