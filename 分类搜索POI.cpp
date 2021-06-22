#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s;
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		int N;
		scanf("%d",&N);
		s.push_back(N);		
	}
	sort(s.begin(),s.end());
	for(int i=0;i<m;i++){
	    int M,cnt;
		scanf("%d",&M);
		cnt = upper_bound(s.begin(),s.end(),M)-lower_bound(s.begin(),s.end(),M);
		printf("%d\n",cnt);
	} 
}
