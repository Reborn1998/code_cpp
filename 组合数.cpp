#include<iostream>
using namespace std;
long long int comb(int n,int m){
	if(n-m<m) m=n-m;
	if(m==0) return 1;
	return comb(n-1,m-1)*n/m;
}
int main(){
	int x,y;
	while(cin>>x>>y)
	   cout<<comb(x,y)<<endl;
} 
