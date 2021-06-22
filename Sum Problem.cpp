#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int s;
		s=0;
		for(int i=1;i<=n;i++){
			s+=i;
		}
		cout<<s<<endl;
	}
} 
