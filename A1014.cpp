#include<bits/stdc++.h>
using namespace std;
const int maxn = 22;
const int maxc = 1010;
int n,m,k,q;
int convertTime(int  h,int m){
	return 60*h+m;
}
void printTime(int x){
	int h = x/60,m=x%60;
	printf("%02d:%02d\n",h,m);
}
queue<int> Q[maxn];
int qend[maxn];
int custom[maxc];
int endTime[maxc];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<n;i++) qend[i] = convertTime(8,0);
	for(int i=1;i<=k;i++) scanf("%d",&custom[i]);
	int t = convertTime(8,0);
	int i,c; 
	for(i=1;i<=k;i++){
		int idx=0,ms=0x7fffffff;
		for(int j=0;j<n;j++) {
			if(Q[j].size()<ms){
				ms = Q[j].size();
				idx=j;
			}
		}
		if(Q[idx].size()==m){
			int minE=0x7fffffff;
			for(int j=0;j<n;j++){
				if(endTime[j]<minE){
					minE = endTime[j];
					idx = j;
				}
			}
			t = minE;
//			cout<<t<<">"<<endl;
			for(int j=0;j<n;j++){
				if(endTime[j]==minE){
					custom[Q[j].front()] = t;
					Q[j].pop();
					c = Q[j].front();
					endTime[j] = t+ custom[c];
				}
			}
		}
		if(t>=convertTime(17,0)) break;
//		cout<<"´°¿Ú£º"<<idx<<"eT"<<endTime[idx]<<endl;
		Q[idx].push(i);	
		if(Q[idx].size()==1){
			c = Q[idx].front();
			endTime[idx] = t+custom[c];
		}
			
	}
	for(i;i<=k;i++) custom[i]=-1;
	for(i=0;i<n;i++){
		if(!Q[i].empty()){
			c = Q[i].front();
			custom[c] = endTime[i];
			Q[i].pop();
		}
		while(!Q[i].empty()){
			c = Q[i].front();
			int temp = custom[c];
			custom[c] = endTime[i]<convertTime(17,0)?endTime[i]+temp:-1;
			endTime[i] = endTime[i]+temp;
			Q[i].pop();
		}
	}
	for(i=0;i<q;i++){
		int c;
		scanf("%d",&c);
		if(custom[c]==-1) printf("Sorry\n");
		else printTime(custom[c]);
	}
}
