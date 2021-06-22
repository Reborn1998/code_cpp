#include<iostream>
#include<algorithm>
using namespace std;
struct Moom{
	double sum;
	double Money;
}moom[1010];
bool cmp(Moom a,Moom b){
	return a.Money/a.sum>b.Money/b.sum;
}
int main(){
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&moom[i].sum);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&moom[i].Money);
	}
	sort(moom,moom+n,cmp);
	double votal = 0;
	for(int i=0;i<n;i++){
		if(d>moom[i].sum){
			votal += moom[i].Money;
			d -= moom[i].sum; 
		}else{
			votal += d * (moom[i].Money/moom[i].sum);
			break;
		}
	}
	printf("%.2f",votal);
}
