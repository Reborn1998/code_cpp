#include<bits/stdc++.h>
using namespace std;
const int N=1111;
int n,m,k;
int cur;
vector<int> G[N];
//bool vis[N];
//void DFS(int v){
//	if(v==cur){		
//		return;
//	}
//	vis[v] = true;
//	for(int i=0;i<G[v].size();i++){
//		if(!vis[G[v][i]])
//			DFS(G[v][i]);
//	}
//}
//
//int main(){
//	scanf("%d%d%d",&n,&m,&k);
//	for(int i=0;i<m;i++){
//		int a,b;
//		scanf("%d%d",&a,&b);
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//	for(int i=0;i<k;i++){
//		scanf("%d",&cur);
//		memset(vis,false,sizeof(vis));
//		int block=0;
//		for(int j=1;j<=n;j++){
//			if(!vis[j]&&j!=cur){
//				DFS(j);
//				block++;
//			}
//		}
//		printf("%d\n",block-1); 
//	}	
//}

int father[N];
int isRoot[N];

int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
		int z=a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA!=faB){
		father[faA] = faB;
	}
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int cur;
	for(int q=0;q<k;q++){
		scanf("%d",&cur);
		init(n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<G[i].size();j++){
				int u=i,v=G[i][j];
				if(u==cur||v==cur) continue;
				Union(u,v);
			}
		}
		int block = 0;
		for(int i =1;i<=n;i++){
			if(i==cur) continue;
			int f = findFather(i);
			if(isRoot[f]==0) {
				isRoot[f]++;
				block++;
			}
			
		}
		printf("%d\n",block-1);
	}
}
