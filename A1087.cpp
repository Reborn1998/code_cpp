#include<bits/stdc++.h>
using namespace std;
const int maxn = 222;
const int INF = 0x7fffffff;
int n,k;
map<string,int> sti;
map<int,string> its;
int G[maxn][maxn],d[maxn];
int vis[maxn];
int h[maxn];
int cnt=0;
int getID(string str){
	if(sti.find(str)==sti.end()){
		sti[str] = cnt;
		its[cnt] = str;
		cnt++;
	}
	return sti[str];
}
//void Dijkstra(int s){
//	memset(vis,false,sizeof(vis));
//	fill(d,d+maxn,INF);
//	
//}
int minCost=INF,minDis=INF,maxH=0,avgH=0;
vector<int>temp,ans;
void DFS(int s,int dis,int totalH,int totalC,vector<int> v){
	if(s==getID("ROM")){
		if(dis<minDis){
			minDis=dis;
			cnt=1;
			maxH=totalH;
			avgH=totalH/(v.size()-1);
			ans = v;
		}else if(dis==minDis){
			cnt++;
			if(totalH>maxH){
				maxH=totalH;
				avgH=totalH/(v.size()-1);
				ans = v;
			}else if(totalH==maxH&&totalH/(v.size()-1)>avgH){
				avgH=totalH/(v.size()-1);
				ans = v;
			}
		}
		return;
	}
	vis[s] = dis;
	for(int i=0;i<n;i++){
		if(G[s][i]>0&&vis[s]+G[s][i]<=vis[i]){
			v.push_back(i);
			DFS(i,vis[s]+G[s][i],totalH+h[i],totalC,v);
			v.pop_back();
		}
	}
}
int main(){
	string start,city1,city2;
	int t;
	cin>>n>>k>>start;
	getID(start);
	for(int i=1;i<n;i++){
		cin>>city1>>t;
		getID(city1);
		h[i] = t;
	}
	
	for(int i=0;i<k;i++){
		cin>>city1>>city2>>t;
		int id1 = getID(city1);
		int id2 = getID(city2);
		G[id1][id2] = G[id2][id1] = t;
	}		
	fill(vis,vis+maxn,INF);
	temp.push_back(0);
	DFS(0,0,0,0,temp);
	printf("%d %d %d %d\n",cnt,minDis,maxH,avgH);
	cout<<its[0];
	for(int i=1;i<ans.size();i++){
		cout<<"->"<<its[ans[i]];
	}
	
}
