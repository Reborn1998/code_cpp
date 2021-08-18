#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
double num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&num[i]);
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=(long long )(num[i]*1000*(n-i)*(i+1));
	}
	printf("%.2lf",sum/1000.00);
} 
