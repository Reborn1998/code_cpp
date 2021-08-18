#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
double p,r;
struct Node{
	double data;
	vector<int> child;
};
Node node[maxn];
int maxDepth=0;
int cnt=0;
void DFS(int x,int depth){
	if(node[x].child.size()==0){
		if(depth>maxDepth){
			maxDepth=depth;
			cnt=1;
		}else if(depth==maxDepth){
			cnt++;
		}
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1); 
	}
}
double hprice(int x){
	double ans=p;
	for(int i=0;i<x;i++){
		ans*=(1+r/100);
	}
	return ans;
} 
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int root;
	for(int i=0;i<n;i++){
		int parent;
		scanf("%d",&parent);
		if(parent!=-1){
			node[parent].child.push_back(i);
		}else root = i;
	}
	DFS(root,0);
	printf("%.2lf %d",hprice(maxDepth),cnt);
}
