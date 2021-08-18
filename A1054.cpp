#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	map<int,int> count;
	int col;
	for(int i=0;i<n*m;i++){
		scanf("%d",&col);
		if(count.find(col)!=count.end()) count[col]++;
		else count[col] = 1;
	}
	int k=0,Max=0;
	for(map<int,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>Max){
			k=it->first;
			Max=it->second;
		}
	}
	printf("%d",k);
}
