#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n;
int num[maxn];
int CBT[maxn];
int cnt=0;
void inorder(int x){
	if(2*x<=n) inorder(2*x);
	CBT[x] = num[cnt++];
	if(2*x+1<=n)inorder(2*x+1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}	
	sort(num,num+n);
	inorder(1);
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i!=n)printf(" ");
	}
}
