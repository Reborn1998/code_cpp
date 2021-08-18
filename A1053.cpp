#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int weight;
	vector<int> child;
}node[maxn];
int n,m,s;
void DFS(int x,int sum,vector<int> temp){
	sum+=node[x].weight;
	if(node[x].child.size()==0){
		if(sum==s){
			for(int i=0;i<temp.size();i++){
				printf("%d",node[temp[i]].weight);
				if(i!=temp.size()-1)printf(" ");
			}
			printf("\n");
		} 
		return;
	}
	if(sum>s) return;
	for(int i=0;i<node[x].child.size();i++){
		temp.push_back(node[x].child[i]);
		DFS(node[x].child[i],sum,temp);
		temp.pop_back();
	}
}
bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].weight);
	}
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[ID].child.push_back(id);
			}
			sort(node[ID].child.begin(),node[ID].child.end(),cmp);
		}
	}
	vector<int> ans;
	ans.push_back(0); 
	DFS(0,0,ans);
}
