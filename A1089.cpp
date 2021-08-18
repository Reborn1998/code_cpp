#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;
int n;
int origin[maxn],tempOri[maxn];
int changed[maxn];
int main(){
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&origin[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&changed[i]);
	}
	int i=0,cnt=1;
	int flag=2;
	for(;i<n-1;i++){
		if(i+1<n){
//			cout<<changed[i]<<" "<<changed[i+1]<<endl;
			if(changed[i]<changed[i+1]) cnt++;
			else {
				if(cnt==1) flag=0;
				v.push_back(cnt);
				cnt=1;
			}
		}
	}
//	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
//	}
//	cout<<endl;
	int m = v[0];	
	if(v.size()>2){
		sort(v.begin(),v.end());
		if(v[v.size()-1]%v[1]!=0) flag=0;
	}
	if(flag){
		sort(v.begin(),v.end());
		int group=v[0];
		int i=0;
		for(;i+2*group<n;i+=2*group){
			sort(changed+i,changed+i+2*group);
		}
		sort(changed+i,changed+n);
//		sort(changed,changed+n);
		cout<<"Merge Sort\n";
		for(i=0;i<n;i++){
			cout<<changed[i];
			if(i!=n-1) cout<<" ";
		}
	}
	else{
		sort(changed,changed+m+1); 
		cout<<"Insert Sort\n";
		for(i=0;i<n;i++){
			cout<<changed[i];
			if(i!=n-1) cout<<" ";
		}
	}
}
