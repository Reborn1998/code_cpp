#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn];
int  b[maxn];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    a[n] = b[m] = 0x7fffffff;
    int target = (n+m-1)/2;
    int id=0;
    int x=0,y=0;
    while(id<target){
     	
        if(a[x]<b[y])cout<<a[x++]<<" ";
        else cout<<b[y++]<<" ";
        id++;
    }
   
    if(a[x]<b[y])
        printf("%d\n",a[x]);
    else
        printf("%d\n",b[y]);
}
