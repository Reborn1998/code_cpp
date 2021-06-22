#include<iostream>
using namespace std;
int main(){
	char ch;
	int n;
	while(cin>>ch>>n){
		for(int i=1;i<=n;i++){
		   for(int j=1;j<=n-i;j++)cout<<" ";
		   for(int k=1;k<=2*i-1;k++)cout<<ch;
		   cout<<endl;
		} 


	}
} 
