#include<bits/stdc++.h>
using namespace std;
const int N=52;
set<int> st[N]; 
void compare(int x,int y){
	int total = st[y].size(),same=0;
	for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++){
		if(st[y].find(*it)!=st[y].end()) same++;
		else total++;
	}
	printf("%.1f%%\n",same*100.0/total);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m,a;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&a);
			st[i].insert(a);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		compare(x,y);
	}
}
