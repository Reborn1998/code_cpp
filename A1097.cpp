#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
set<int> st;
struct Node{
	int adress,data,next;
	int flag;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag<b.flag;
	return a.order<b.order;
}
int main(){
	int start,n;
	scanf("%d%d",&start,&n);
	for(int i=0;i<maxn;i++){
		node[i].flag = 2*maxn;
		node[i].order = maxn;
	}
	
	
	for(int i=0;i<n;i++){
		int adr;
		scanf("%d",&adr);
		scanf("%d%d",&node[adr].data,&node[adr].next);
		node[adr].adress = adr;
		node[adr].flag=n+i;
//		if(st.find(abs(node[adr].data))!=st.end()){
//			node[adr].flag = cnt++;	
//		}else{
//			node[adr].flag = 0;
//			st.insert(abs(node[adr].data));
//		}
	}
	int p = start;
	int cnt=1;
	int k=0;
//	cout<<"=======================\n";
	while(p!=-1){
		node[p].order = k++;
		if(st.find(abs(node[p].data))!=st.end()){
			node[p].flag = cnt++;	
		}else{
			node[p].flag = 0;
			st.insert(abs(node[p].data));
		}
//		cout<<node[p].adress<<" "<<node[p].data<<" "<<node[p].flag<<" "<<node[p].order<<endl;
		p = node[p].next;	
	}
	cnt--;
	sort(node,node+maxn,cmp);
	p=start;
//	cout<<"=======================\n";
//	for(int j=0;j<n;j++){
//		
//		cout<<node[j].adress<<" "<<node[j].data<<" "<<node[j].flag<<" "<<node[j].order<<endl;	
//	}
//	cout<<"=======================\n";
	for(int i=0;i<k-cnt;i++){
		if(i!=k-cnt-1){
			printf("%05d %d %05d\n",node[i].adress,node[i].data,node[i+1].adress);
		}else{
			printf("%05d %d -1\n",node[i].adress,node[i].data);
		}
	}
	for(int i=k-cnt;i<k;i++){
		if(i!=k-1){
			printf("%05d %d %05d\n",node[i].adress,node[i].data,node[i+1].adress);
		}else{
			printf("%05d %d -1",node[i].adress,node[i].data);
		}
	}
} 
