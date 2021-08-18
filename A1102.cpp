#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n;
struct Node{
	int lc;
	int rc;
};
Node nodes[maxn];
int inq[maxn];
int pn=0;
void change(int x){
	swap(nodes[x].lc,nodes[x].rc);
	if(nodes[x].lc!=-1) change(nodes[x].lc);
	if(nodes[x].rc!=-1) change(nodes[x].rc);
}
void inorder(int x){
	
	if(nodes[x].lc!=-1) inorder(nodes[x].lc);
	printf("%d",x);
	pn++;
	if(pn!=n) printf(" ");
	if(nodes[x].rc!=-1) inorder(nodes[x].rc);
}
int bn=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		printf("%d",temp);
		bn++;
		if(bn!=n) printf(" ");
		if(nodes[temp].lc!=-1) q.push(nodes[temp].lc);
		if(nodes[temp].rc!=-1) q.push(nodes[temp].rc);
	}
}
int main(){
	scanf("%d",&n);
	char l,r;
	for(int i=0;i<n;i++){
		scanf("%*c%c %c",&l,&r);
		
		if(l>='0'&&l<='9'){
			nodes[i].lc=l-'0';
			inq[l-'0']=1;
		}else{
			nodes[i].lc=-1;
		}
		
		if(r>='0'&&r<='9'){
			nodes[i].rc=r-'0';
			inq[r-'0']=1;
		}else{
			nodes[i].rc=-1;
		}
	}
	int root;
	for(int i=0;i<n;i++) if(inq[i]==0) root=i;
	change(root);
	BFS(root);
	printf("\n");
	inorder(root);
	
}
