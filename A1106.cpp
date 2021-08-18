#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
double p,r;
struct Node{
	double product;
	vector<int> child;
};
Node node[maxn];
vector<int> v;
int mindepth=maxn;
void DFS(int x,int depth){
	if(v.size()==depth){
//		cout<<x<<" ?";
		v.push_back(0);
	}
	if(node[x].child.size()==0){
		v[depth]++;
		if(depth<mindepth) mindepth = depth;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1);
	}
}
double lprice(int x){
	double ans=p;
	for(int i=0;i<x;i++){
		ans*=(1+r/100);
	}
	return ans;
} 
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int k,id;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[i].child.push_back(id);
			}
		}
	}
	v.push_back(0);
	DFS(0,1);
//	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//	cout<<endl;
	printf("%.4lf %d",lprice(mindepth-1),v[mindepth]);	
}
