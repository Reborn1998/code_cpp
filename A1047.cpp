#include<bits/stdc++.h>
using namespace std;
int getID(char name[]){
	int id= 0;
	for(int i=0;i<3;i++){
		id = id*26+(name[i]-'A');
	}
	id = id*10+(name[3]-'0');
	return id;
}
void getName(int id,char name[]){
	int num[4];
	num[0] = id%10;
	id/=10;
	for(int i=1;i<=3;i++){
		num[i] = id%26;
		id = id/26;
	}
	for(int i=3;i>0;i--){
		name[3-i] = 'A' + num[i]; 
	}
	name[3] = '0'+num[0];
	name[4] = '\0';
}
bool cmp(int a,int b){
	char ma[5];
	getName(a,ma);
	char mb[5];
	getName(b,mb);
	return strcmp(ma,mb)<0;
}
const int maxn = 40010;
char name[maxn][5];
const int maxc = 2510;
vector<int> course[maxc];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	char name[5];
	int num;
	for(int i=0;i<n;i++){	
		scanf("%s %d",name,&num);
		int id = getID(name);
		for(int j=0;j<num;j++){
			int c;
			scanf("%d",&c);
			course[c].push_back(id);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++){
			getName(course[i][j],name);
			printf("%s\n",name);
		}
	}
	
}
