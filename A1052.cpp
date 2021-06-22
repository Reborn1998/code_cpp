#include<bits/stdc++.h>
using namespace std;
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[100010];
bool cmp(Node a,Node b){
	if(!a.flag || !b.flag){
		return a.flag>b.flag;
	}
	return a.data<b.data;
}
int main(){
	for(int i=0;i<100010;i++){
		node[i].flag = false;
	}
	int n,head;
	scanf("%d%d",&n,&head);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		node[a].address = a;
		node[a].data = b;
		node[a].next = c;
	}
	int cnt = 0;
	int p = head;
	while(p!=-1){
		node[p].flag = true;
		cnt++;
		p = node[p].next;
	}
	if(cnt==0){
		printf("0 -1");
		return 0;
	}
	sort(node,node+100010,cmp);
	printf("%d %05d\n",cnt,node[0].address);
	for(int i=0;i<cnt;i++){
		if(i==n-1){
			node[i].next = -1;
			printf("%05d %d %d",node[i].address,node[i].data,-1);
		}else{
			node[i].next = node[i+1].address;
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i].next);
		}
		
	}
}
