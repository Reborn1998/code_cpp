#include<iostream>
#include<vector>
using namespace std;
int city,visit[1000];
int N,M,K;
vector<int>v[1000]; 
void dfs(int curcity){
	visit[curcity]=1;
	for(int i:v[curcity]){
		if(i!=city&&!visit[i]) dfs(i);
	}
}
int main(){

	cin>>N>>M>>K;
	int j,k;
	for(int i=0;i<M;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}	
	while(K--){
		cin>>city;
		for(int i=1;i<=N;i++) visit[i]=0;
		j=0;
		for(int i=1;i<=N;i++){
			if(!visit[i]&&i!=city){
				j++;
				dfs(i);
			}
		}
		cout<<j-1<<endl;
	}
} 
