#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T,N;
    int a[1001];
    cin>>T;
    while(T--){
    	cin>>N;
    	for(int i=0;i<N;i++){
    		cin>>a[i];
		}
		sort(a,a+N);
		for(int i=0;i<N-1;i++){
    		cout<<a[i]<<" ";
		}
		cout<<a[N-1];
		cout<<endl;	
	}
} 
