#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
int pre[50],in[50],post[50];
int n;
Node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;
	}
	Node *node = new Node();
	node->data = post[postR];
	int i;
	for(i=inL;i<inR;i++){
		if(in[i]==post[postR]){
			break;
		}
	}
	int Numleft = i-inL;
	node->lchild = create(postL,postL+Numleft-1,inL,i-1);
	node->rchild = create(postL+Numleft,postR-1,i+1,inR);
	return node;
}
void BFS(Node *root){
	queue<Node*> q;
	q.push(root);
	bool flag = true;
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->lchild!=NULL) q.push(temp->lchild);
		if(temp->rchild!=NULL) q.push(temp->rchild);
		if(flag){
			printf("%d",temp->data);
			flag = !flag;
		}else{
			printf(" %d",temp->data);
		}
		
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	Node *root = create(0,n-1,0,n-1);

	BFS(root);
}
