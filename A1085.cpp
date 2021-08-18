#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long  num[maxn];
long long n,p;
int binarySearch(int i,long long x){
	if(num[n-1]<x) return n;
	int l=i+1,r=n-1;
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(num[mid]<=x) l = mid+1;
		else if(num[mid]>x) r=mid;
	}
	return l;
}
int main(){

    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
//    int idx=0,idx1=0;
//    int mcnt = 0;
//    for(;idx1<n;idx++){
//    	while(num[idx1]<=p*num[idx]) {
//    		idx1++;
//    		if(idx1==n){
//    			break;
//			}
//		}
//    	if(idx1-idx>mcnt&&num[idx1-1]<=p*num[idx]) mcnt = idx1-idx;
//	}
//    cout<<mcnt;
	int idx=0;
	int i=0;
	int cnt=1;
	while(idx<n){
		idx = binarySearch(i,num[i]*p);
		if(idx-i>cnt) cnt=idx-i;
		i++;
	}
//	for(int i=0;i<n;i++){
//		idx = binarySearch(i,num[i]*p);
//		if(idx-i>cnt) cnt=idx-i;
//	}
	cout<<cnt;
}

