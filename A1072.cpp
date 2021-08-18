#include<bits/stdc++.h>
using namespace std;
const int maxn = 1015;
int n,m,k,D;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
const int INF = 0x7fffffff; 
int getID(char city[]){
	int idx = 0;
	int id=0;
	int c=0;
	if(city[idx]=='G'){
		idx++;
		c=n;
	}	
	int len = strlen(city) ;
	for(idx;idx<len;idx++){
		id = id*10+city[idx]-'0';
	}
	return id+c;
}
void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n+m;j++){
			if(!vis[j]&&d[j]<MIN){
				u=j;
				MIN = d[j];
			}
		} 
		if(u==-1) return;
		vis[u] = true;
		for(int v=1;v<=n+m;v++){
			if(!vis[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u]+G[u][v];
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&D);
	int w;
	
	char city1[5],city2[5];
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",&city1,&city2,&w);
		int id1 = getID(city1);
		int id2 = getID(city2);
		G[id1][id2] = G[id2][id1] = w;
	}
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<=m+n;i++){
//		init();
		double minDis=INF,avg=0;
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>D){
				minDis = -1;
				break;
			}
			if(d[j]<minDis) minDis = d[j];
			avg+= 1.0*d[j]/n;
		} 
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}else if(minDis==ansDis&&avg<ansAvg){
			ansID = i;
			ansAvg=avg;
		}
	}
	if(ansID==-1) printf("No Solution\n");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
} 
