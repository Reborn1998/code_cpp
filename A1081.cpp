#include<bits/stdc++.h>
using namespace std;
long long  gcd(long a,long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

struct Fraction{
	long long up,down;
};
Fraction reduction(Fraction result){
	
}
Fraction add(Fraction a,Fraction b){
	Fraction result;
	long long x = a.up*b.down+b.up*a.down;
	long long y = a.down*b.down;

		
	long long g = gcd(abs(x),abs(y));
//	cout<<g<<endl;	
	if(y<0) x=-x,y=-y;
	if(x==0){
		result.up = 0;
		result.down = 1;
	}else{
		result.up = x/(g?g:1);
		result.down = y/(g?g:1);
	}
		cout<<"=================\n";
	cout<<a.up<<" "<<a.down<<endl;
	cout<<b.up<<" "<<b.down<<endl;
	cout<<y<<" 2"<<endl;
	cout<<"========------========\n";

	return result;
}
int main(){
	int n;
	scanf("%d",&n);
	Fraction a,b;
	a.up=0;
	a.down=1;
	for(int i=0;i<n;i++){	
		scanf("%lld/%lld",&b.up,&b.down);
		a  = add(a,b);
//		cout<<a.up<<" "<<a.down<<endl;
	}
	
	int x = a.up/a.down;
	a.up -= (a.up<0?-1:1)*a.down*x; cout<<"s";
	if(x!=0){
		printf("%d",x);
		if(a.up!=0) printf(" ");
		a.up = abs(a.up);
	}
	if(a.up!=0 && a.down!=1){
		printf("%lld/%lld",a.up,a.down);
	}
}
