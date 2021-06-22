#include<iostream>
using namespace std;
int num[100010];
bool b[100010];
int main(){
	int n;
	cin>>n;
	long long cnt=0,max=0;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]>max){
			b[i]=true;
			max=num[i];
		}else{
			b[i]=false;
		}
	}
	long long min=1000000000;
	for(int i=n-1;i>=0;i--){
		if(num[i]<min){
			if(b[i])cnt++;
			min=num[i];
		}
		else{
			b[i]=false;
		}
	}
	cout<<cnt<<endl;
	
	bool flag = false;
	for(int i=0;i<n;i++){
		if(b[i]){
			if(flag) cout<<" ";
			cout<<num[i];
			flag = true;
		} 
	}
	cout<<endl;
	
} 
