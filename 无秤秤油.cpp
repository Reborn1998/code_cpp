#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int cnt = 0 ; 
		while(n){
			
			if(n&0x0001) cout<<"  "<<pow(2,cnt)/20.0<<"kg"<<endl;
			cnt++;
			n=n>>1;
		}
	}
}
