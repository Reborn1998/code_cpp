#include<iostream>
#include<cmath> 
using namespace std;
int main(){
	int N,X,K,i,j;
	while(cin>>N){
		if(N == 0){
			break;
		}
		for(i=pow(N,1.0/2);i>=2;){
			int s = i*i;
			if(s==N){
			    cout<<i<<" "<<2<<endl;
			    break;
			}
			
			for(j=3;pow(i,j)<=N;j++){
				s*=i;
				if(s==N){
				cout<<i<<" "<<j<<endl;
				break;	
				}
			}
			if(pow(i,j)>N){
			    i--;
		    }
		    else if(s==N) break;
			
		}
		if(i==1) cout<<0<<" "<<0<<endl;
	}
} 
