#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
int pre[33],in[33],post[33];
int n; 
Node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;
	}
	Node* root = new Node();
	root->data = post[postR];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==post[postR]) break;
	}
	int l = i-inL;
	root->left = create(postL,postL+l-1,inL,i-1);
	root->right = create(postL+l,postR-1,i+1,inR);
	return root;
}
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		printf("%d",temp->data);
		num++;
		if(num!=n) printf(" ");
		if(temp->left!=NULL) q.push(temp->left);
		if(temp->right!=NULL) q.push(temp->right);
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
	Node *root=create(0,n-1,0,n-1);
	BFS(root);
	
} 
