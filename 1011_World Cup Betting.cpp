#include<iostream>
using namespace std;
double max(double a,double b,double c){
	if(a>b and a>c){
		return a;
	}
	if(b>a and b>c){
		return b;
	}
	return c;
}
int main(){
	double sum=1;
	char result[3] = {'W','T','L'};
	double a,b,c;
	for(int i=0;i<3;i++){
		cin>>a>>b>>c;
		sum *= max(a,b,c);
		if(max(a,b,c)==a) cout<<"W"<<" ";
		if(max(a,b,c)==b) cout<<"T"<<" ";
		if(max(a,b,c)==c) cout<<"L"<<" ";
	}
	printf("%.2lf",(sum*0.65-1.0)*2.0);
	
} 
