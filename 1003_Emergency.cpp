#include<iostream>
#include<vector>
using namespace std;
int N,M,C1,C2;
int num_of_team[500],dis[500][500],mindis[500],paths,teams;
vector<int> v[500];

void dsp(int curcity,int curlen,int curteam){
	if(curlen>mindis[curcity]) return;
	if(curcity == C2){
		if(curlen == mindis[curcity]){
			paths++;
			if(curteam>teams) teams = curteam;
		}
		else{
			mindis[curcity];
			paths = 1;
			teams = curteam;
		}
	}
	else{
		if(curlen<mindis[curcity]) mindis[curcity] = curlen;
		for(int i=0;i<v[curcity].size();i++){
			dsp(v[curcity][i],curlen+dis[curcity][v[curcity][i]],curteam+num_of_team[v[curcity][i]]);
		}
	}
}

int main(){
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++)
		cin>>num_of_team[i];
	int j,k,l;
	for(int i=0;i<N;i++){
		cin>>j>>k>>l;
		v[j].emplace_back(k);
		v[k].emplace_back(j);
		dis[j][k] = dis[k][j] = l;
	}
	for(int i = 0;i<500;i++) mindis[i] = 10000000000;
	dsp(C1,0,num_of_team[C1]);
	cout<<paths<<" "<<teams;
} 
