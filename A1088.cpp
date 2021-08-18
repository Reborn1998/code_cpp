#include<bits/stdc++.h>
using namespace std;
struct Fraction{
	long long up,down;
}a,b;
long long gcd(long long a,long long b){
	return b==0? a:gcd(b,a%b);
}
Fraction reduction(Fraction s){
	if(s.down<0){
		s.down = -s.down;
		s.up = -s.up;
	}
	if(s.up==0){
		s.down = 1;
	}else{
		int d = gcd(abs(s.up),abs(s.down));
		s.up /= d;
		s.down /= d;
	}
	return s;
}
Fraction add(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down+x.down*y.up;
	ans.down = x.down * y.down;
	return reduction(ans); 
}
Fraction sub(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down-x.down*y.up;
	ans.down = x.down * y.down;
	return reduction(ans) ;
}
Fraction mul(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.up;
	ans.down = x.down * y.down;
	return reduction(ans) ;
}
Fraction divide(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down;
	ans.down = x.down * y.up;
	return reduction(ans) ;
}
void showResult(Fraction r){
//	cout<<r.up<<"/"<<r.down<<endl;
	r = reduction(r);
//	cout<<r.up<<"/"<<r.down<<endl;
	if(r.up<0) printf("(");
	if(r.down==1) printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%lld/%lld",r.up,r.down);
	}
	if(r.up<0) printf(")");
}
int main(){
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);

	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n");
	
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a,b));
	printf("\n");
	
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(mul(a,b));
	printf("\n");
	
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up==0) printf("Inf");
	else 	showResult(divide(a,b));
	printf("\n");
} 
