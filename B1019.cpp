#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n[4];
	int num;
	cin>>num;
	int max=0,min=0;
	while(num!=6174){
		n[0]=num/1000;
		n[1]=num%1000/100;
		n[2] = num%100/10;
		n[3] = num%10;
		sort(n,n+4);
		num = (n[3]*1000+n[2]*100+n[1]*10+n[0])- (n[0]*1000+n[1]*100+n[2]*10+n[3]);
		cout<<n[3]<<n[2]<<n[1]<<n[0]<<" - "<<n[0]<<n[1]<<n[2]<<n[3]<<" = "<< num<<endl;
	}
}
