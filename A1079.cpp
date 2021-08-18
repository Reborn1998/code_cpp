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
double sum=0;
void DFS(int x,double price){
	if(node[x].child.size()==0){
		sum+=node[x].product*price;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		int c = node[x].child[i];
		change(c,price*(1+r/100));
	}
}
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int k,id;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0){
			scanf("%lf",&node[i].product);
		}else{
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[i].child.push_back(id);
			}
		}
	}
	DFS(0,p);
	printf("%.1lf",sum);	
}
