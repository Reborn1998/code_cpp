#include<iostream>
using namespace std;
int getweek(int y,int m,int d){
	if(m<=2){y--; m+=12;	}
	int c=y/100;
	y=y%100;
	int w=(y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7;
	if(w<0) w+=7;
	return w;
}
int main(){
	int n,r;
	while(cin>>n){
		int a[7]={0};
		for(int i=1900;i<1900+n;i++){			
			for(int j=1;j<13;j++){
			    r=getweek(i,j,7);
				a[r]++;	
			}
		}
	for(int i=1;i<7;i++) cout<<a[i]<<" ";
	cout<<a[0]<<
	endl;	
	}
	
}
