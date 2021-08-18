#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,root;
vector<int> G[N];


bool isRoot[N];
int father[N];
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
		int z=a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA!=faB){
		father[faA] = faB;
	}
}

int maxDepth=0;
vector<int> temp,ans;
void DFS(int x,int depth,int last){
	if(depth>maxDepth){
		maxDepth = depth;
		temp.clear();
		temp.push_back(x);
	}
	if(depth==maxDepth){
		temp.push_back(x);	
	}
	for(int i=0;i<G[x].size();i++){
		if(G[x][i]!=last){
			DFS(G[x][i],depth+1,x);

		}		
	}
}
void init(){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	
	int block=0;
	for(int i=1;i<=n;i++){
		int f = findFather(i);
//		cout<<f<<endl;
		if(!isRoot[f]){
			block++;
			isRoot[f] = true;
		}
	}
	if(block!=1){
		printf("Error: %d components",block);
		return 0;
	}

	DFS(1,0,1);
	ans = temp;
	DFS(ans[0],0,ans[0]);
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans[0]);
	for(int i=1;i<ans.size();i++){
		if(ans[i]!=ans[i-1])
			printf("%d\n",ans[i]);
	}
	
}
