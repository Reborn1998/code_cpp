#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
int G[maxn][maxn],C[maxn][maxn];
int vis[maxn];
int n,m,s,d;
int mind=0; 
int finalcost=0x7fffffff,finaldistance=0x7fffffff;
vector<int> temp,ans;
void DFS(int cur,int distance,int cost,vector<int> v){
	if(distance>finaldistance||cost>finalcost) return;
	if(cur==d){
//		cout<<"?";
		if(distance<finaldistance){
			finaldistance = distance;
			finalcost = cost;
			ans = v;
		}else if(distance == finaldistance){
			if(cost<finalcost){
				finalcost = cost;
				ans = v;
			}
		}
		return;
	}

	for(int i=0;i<n;i++){
//		cout<<cur<<" "<<i<<" "<<G[cur][i]<<" "<<vis[i]<<" "<<distance+G[cur][i]<<endl;
		if(G[cur][i]>0&&vis[i]>distance+G[cur][i]){ 
			v.push_back(i);
			int t = vis[cur];
			vis[cur] = distance;
			DFS(i,distance+G[cur][i],cost+C[cur][i],v);
			vis[cur] = t;
			v.pop_back();
		}
	}
}
int main(){
	 scanf("%d%d%d%d",&n,&m,&s,&d);
	 for(int i=0;i<m;i++){
	 	int a,b,x,y;
	 	scanf("%d%d%d%d",&a,&b,&x,&y);
	 	G[a][b] = G[b][a] = x;
	 	C[a][b] = C[b][a] = y;
	 	vis[i] = 0x7fffffff;
	 }
	 temp.push_back(s);
	 DFS(s,0,0,temp);
	 for(int i=0;i<ans.size();i++){
	 	printf("%d ",ans[i]);
	 }
	 printf("%d %d",finaldistance,finalcost);
	 
}
