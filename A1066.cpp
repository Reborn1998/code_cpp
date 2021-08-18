#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,height;
	Node *lc;
	Node *rc;
}*root;
Node* newNode(int v){
	Node* n = new Node();
	n->data = v;
	n->height = 1;
	n->lc=n->rc=NULL;
	return n;
}
int getHeight(Node*root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node*root){
	root->height = max(getHeight(root->lc),getHeight(root->rc))+1;
}
int getBalanceFactor(Node* root){
	return (getHeight(root->lc)-getHeight(root->rc));
}
void L(Node*& root){
	Node *temp = root->rc;
	root->rc = temp->lc;
	temp->lc = root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;	
}
void R(Node*& root){
	Node* temp=root->lc;
	root->lc = temp->rc;
	temp->rc = root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(Node*&root,int v){
	if(root==NULL){
		root = newNode(v);
		return;
	} 
	if(v<root->data){
		insert(root->lc,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			
			if(getBalanceFactor(root->lc)==1){
//				cout<<root->data<<endl;
				R(root);
			}else if(getBalanceFactor(root->lc)==-1){
				L(root->lc);
				R(root);
			}
		} 
	}else{
		insert(root->rc,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rc)==1){
				R(root->rc);
				L(root);
			}else if(getBalanceFactor(root->rc)==-1){
				L(root);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d",root->data);
}
