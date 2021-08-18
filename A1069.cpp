#include<bits/stdc++.h>
using namespace std;
int num[4];
void init(int last){
	for(int i=0;i<4;i++,last/=10){
		num[i] = last%10;
	}
}
int tmax(){
	int sum=0;
	for(int i=3;i>=0;i--){
		sum=sum*10+num[i];
	}
	return sum;
}
int tmin(){
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int Max,Min;
	int last;
	init(n);
	sort(num,num+4);
	Max=tmax();
	Min = tmin();		
	last=Max-Min;
	printf("%04d - %04d = %04d",Max,Min,last);
	while(true){	
		init(last);
		sort(num,num+4);
		Max=tmax();
		Min = tmin();	
		if(last!=Max-Min) {
			printf("\n");
			last =Max-Min;
		}
		else break;	
		printf("%04d - %04d = %04d",Max,Min,last); 		
	}
}
