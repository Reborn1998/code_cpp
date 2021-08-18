#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=110;
struct Node{
	double data;
	vector<int> child;
};
Node node[maxn];
vector<int> v;

void DFS(int x,int depth){
	if(v.size()>depth){
		v[depth]++;
	}else{
		v.push_back(1);
	}
	if(node[x].child.size()==0){
		return;
	}
	
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&id);
			node[ID].child.push_back(id);
		}
	}
	v.push_back(0);
	DFS(1,1);
	int idx=0;
	int Max=0;
	for(int i=1;i<v.size();i++){
		if(v[i]>Max){
			idx=i;
			Max=v[i];
		}
	}
	printf("%d %d",Max,idx);
}
