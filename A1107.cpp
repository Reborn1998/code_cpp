#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int father[maxn]; 
int isRoot[maxn]={0};
int course[maxn]={0};

int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
	 	int z = a;
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

void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(course[h]==0){
				course[h]=i;
			}
			Union(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]) ans++;
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+1+n,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i!=ans) printf(" ");
	}
}

