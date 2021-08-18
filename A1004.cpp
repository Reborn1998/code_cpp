#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=110;
struct Node{
	vector<int> child;
};
Node node[maxn];
vector<int> v;
int maxD=0;
void DFS(int x,int depth){
	if(v.size()==depth){
		
		v.push_back(0);
	}
	if(node[x].child.size()==0){
//		cout<<maxD<<" "<<depth
		if(maxD<depth)maxD=depth;
		v[depth]++;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
//		cout<<"!";
		DFS(node[x].child[i],depth+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[ID].child.push_back(id);
			}
		}
	}
	v.push_back(0);
	DFS(1,1);
	for(int i=1;i<=maxD;i++){
		printf("%d",v[i]);
		if(i!=maxD) printf(" ");
	}
}
