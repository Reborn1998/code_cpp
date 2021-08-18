#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
int main(){
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	while(t--){
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		int cur=1;
		for(int i=1;i<=n;i++){
//			cout<<i<<" s";
			st.push(i);
			
	
			if(st.size()>m){
//				cout<<"2";
				printf("No\n");
				break;
			}
			while(!st.empty()&&arr[cur]==st.top()){
//				cout<<"3";
				st.pop();
				cur++;
			}
			if(i==n&&!st.empty()&&arr[cur]!=st.top()){
//				cout<<"2";
				printf("No\n");
				break;
			}
				
		}
		if(st.empty()) printf("Yes\n");
	}
}
