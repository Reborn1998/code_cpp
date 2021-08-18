#include<bits/stdc++.h>
using namespace std;
const int maxn = 10009;
int num[maxn];
int matrix[maxn][maxn];
int N;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	if(N==1){
		printf("%d",num[0]);
		return 0;
	}
	sort(num,num+N,cmp);
	int m=(int)ceil(sqrt(N*1.0)),n;
	while(N%m!=0){
		m++;
	}
	n = N/m;
	int U=1,D=m,L=1,R=n; 
	int i=1,j=1,now=0;

//	cout<<i<<" "<<j<<" "<<U<<" "<<D<<" "<<R<<" "<<L<<endl;
	while(now<N){
//		cout<<"========\n";
		while(i<R&&now<N){
//			cout<<U<<","<<i<<endl;
			matrix[j][i++] = num[now++];
		}
//		cout<<"========\n";
		while(j<D&&now<N){
//			cout<<j<<","<<R<<endl;
			matrix[j++][i] = num[now++];
		}
//		cout<<"========\n";
		while(i>L&&now<N){
//			cout<<D<<","<<i<<endl;
			matrix[j][i--] = num[now++];
		}
//		cout<<"========\n";
		while(j>U&&now<N){
//			cout<<j<<","<<L<<endl;
			matrix[j--][i] = num[now++];
		}
		i++;j++;
		U++;D--;L++;R--;
		if(now==N-1){
			matrix[j][i] = num[now++];
		}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d",matrix[i][j]);
			if(j!=n) printf(" ");
			else printf("\n");
		}
	}
}
