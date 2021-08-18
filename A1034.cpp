#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,k;
map<string,int> sTi;
map<int,string> iTs;
map<string,int> Gang;
int G[N][N]={0},weight[N]={0};
bool vis[N]={false};
int numPerson=0;
int change(string name){
	if(sTi.find(name)==sTi.end()){
		sTi[name] = numPerson;
		iTs[numPerson] = name;
//		cout<<name<<" "<<numPerson<<endl;
		return numPerson++; 
	}else{
		return sTi[name];
	}
}
void DFS(int x,int& total,int& head,int& num){
	num++;
	vis[x] = true;
	if(weight[head]<weight[x]){
		head = x;
	}
	for(int i=0;i<numPerson;i++){
		if(G[x][i]>0){
//			cout<<x<<" "<<i<<" "<<G[x][i]<<endl; 
			total += G[x][i];
			G[x][i] = G[i][x] = 0;
			if(!vis[i])
				DFS(i,total,head,num);
		}
	} 
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		string a,b;
		int t;
		cin>>a>>b>>t;
		int id1 = change(a);
		int id2 = change(b);
//		cout<<a<<":"<<id1<<" "<<b<<":"<<id2<<endl;
		G[id1][id2] += t; 
		G[id2][id1] += t;
		weight[id1] += t;
		weight[id2] += t;
	}
	for(int i=0;i<numPerson;i++){		
		if(!vis[i]){
			int total=0,head=i,num=0;
			DFS(i,total,head,num);
			if(num>2&&total>k){
				Gang[iTs[head]] = num;
			}
		}
	}
	cout<<Gang.size()<<endl;
	for(map<string,int>::iterator it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
