#include<bits/stdc++.h>
using namespace std;
int n,w[20],c[20],v;
int maxv=0;
void DFS(int index,int sumW,int sumV){
	if(index==n){		
		return;		
	}
	if(w[index]<=v-sumW){
		if(sumV+c[index]>maxv){
			maxv = sumV+c[index];
		}
		DFS(index+1,sumW+w[index],sumV+c[index]);
	}
	DFS(index+1,sumW,sumV);
}
int main(){
	scanf("%d%d",&n,&v);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	DFS(0,0,0);
	printf("%d\n",maxv);
}
