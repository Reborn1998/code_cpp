#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool vis[maxn]={false};
int n,l,k;

void BFS(int x,int &depth,int& num){
	queue<int> q;
	queue<int> temp;
	q.push(x);
	while(!q.empty()){
		int t = q.front();
		q.pop();	
		vis[t] = true;
		for(int i=0;i<G[t].size();i++){
			if(!vis[G[t][i]]){
				vis[G[t][i]] = true;
//				cout<<"?"<<G[t][i]<<endl;
				temp.push(G[t][i]);
				num++;
			}
		
		}
		if(q.empty()) {
//			cout<<depth<<endl;
			q=temp;
			while(!temp.empty()) temp.pop();
			depth++;
			if(depth==l) return;
		}
	}
}
int init(){
	for(int i=1;i<=n;i++)
		vis[i] = false;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		int M,id;
		scanf("%d",&M);
		for(int j=0;j<M;j++){
			scanf("%d",&id);
			G[id].push_back(i);
		}
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		int id;
		scanf("%d",&id);
		int cnt=0,depth=0;
		init();
		BFS(id,depth,cnt);
		printf("%d\n",cnt);	
	}
}
