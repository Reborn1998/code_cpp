#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* lc;
	Node* rc;
	Node* father;
};
int pre[33],in[33],post[33];
int n;
Node* create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	Node* root = new Node();
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(pre[preL]==in[k]) break;
	}
	int l=k-inL;
	root->lc = create(preL+1,preL+l,inL,k-1);
	root->rc = create(preL+1+l,preR,k+1,inR);
	return root;
}
int num=0;
void postS(Node *root){
	if(root->lc!=NULL) postS(root->lc);
	if(root->rc!=NULL) postS(root->rc);
	printf("%d",root->data);
	if(num!=n-1) printf(" ");
	num++;
}
int main(){
//	1 2 3 4 5 6
//	3 2 4 1 6 5
	scanf("%d",&n);
	stack<int> st;
	int idp = 0,idi=0;
	string str;
	int d;
	for(int i=0;i<n*2;i++){
		cin>>str;
		if(str=="Push"){
			cin>>d;
			pre[idp++]=d;
			st.push(d);
		}
		if(str=="Pop"){
			in[idi++]=st.top();
			st.pop();
		}
	}
	Node *root = create(0,n-1,0,n-1);
	postS(root);
} 
