#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node{
	int address,data,next;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main(){
	for(int i=0;i<maxn;i++) node[i].order = maxn;
 	int start,n,k;
	scanf("%d%d%d",&start,&n,&k);
	for(int i=0;i<n;i++){
		int adr;
		scanf("%d",&adr);
		scanf("%d%d",&node[adr].data,&node[adr].next);
		node[adr].address = adr;
	}
	int cnt=1;
	for(int i=start;i!=-1;){
		node[i].order=cnt++;
		i = node[i].next;
	}
	sort(node,node+maxn,cmp);
	int i;
	n=cnt-1;
	for(i=0;i<n/k;i++){
		for(int j=0;j<k/2;j++){
			cout<<i*k+j<<":"<<node[i*k+j].data<<" "<<i*k+k-1-j<<":"<<node[i*k+k-j-1].data<<endl;
			swap(node[i*k+j],node[i*k+k-j-1]);
		}
	}
//	for(int j=0;j<(n%k)/2;j++){
//		cout<<i*k+j<<":"<<node[i*k+j].data<<" "<<i*k+k-1-j<<":"<<node[i*k+k-j-1].data<<endl;
//
//		swap(node[i*k+j],node[i*k+n%k-j-1]);
//	}
	for(int i=0;i<n;i++){
		printf("%05d %d ",node[i].address,node[i].data);
		if(i==n-1) printf("-1");
		else printf("%05d\n",node[i+1].address);
	}
}
