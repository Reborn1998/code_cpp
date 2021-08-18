#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
struct Node{
	int data;
	int lc;
	int rc;
};
Node node[maxn];
int pre[maxn];
int cnt=0;
void inorder(int x){
	if(node[x].lc!=-1) inorder(node[x].lc);
	node[x].data = pre[cnt++];
	if(node[x].rc!=-1) inorder(node[x].rc);
}
int num=0;
void BFS(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		num++;
		printf("%d",node[temp].data);
		if(num!=n) printf(" ");
		if(node[temp].lc!=-1) q.push(node[temp].lc);
		if(node[temp].rc!=-1) q.push(node[temp].rc);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&node[i].lc,&node[i].rc);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}	
	sort(pre,pre+n);
	inorder(0);
	BFS(0);
}
