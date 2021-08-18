#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
string num[maxn];
long long  transform(string a,int r){
    long long sum=0;
    int n = a.size()-1;
    for(int i=0;i<a.size();i++){
        int x;
        if(a[i]>='a'&&a[i]<='z') x = a[i]-'a'+10;
        else x = a[i] - '0';
        sum = sum*r + x;
    }
    return sum;
}
int main(){
    string a,b;
    int tag,radix;
    cin>>a>>b>>tag>>radix;
    if(tag==2) swap(a,b);
    long long n1 = transform(a,radix);
//    cout<<n1<<endl;
    int maxr=0;
    for(int i=0;i<b.size();i++){
        int x;
//        cout<<"bi"<<b[i]<<" ";
        if(b[i]>='a'&&b[i]<='z') x = b[i]-'a'+10;
        else if(b[i]>='0'&&b[i]<='9') x = b[i] - '0';
//        cout<<x<<" ";
        if(x>maxr) maxr = x;
    }
    int i;
//    cout<<maxr<<endl;
    long long l,r,mid;
    l=maxr+1,r=max(l,n1+1);

    while(l<=r){
        mid = (l+r)/2;
//        cout<<l<<" "<<r<<endl;
//        cout<<transform(b,mid)<<" zhengque:" <<n1<<endl;
//		if(r<100) cout<<"s"<<l<<" "<<r<<endl;
         if(transform(b,mid)>n1||transform(b,mid)<0){
            r=mid-1;
        }
        else if(transform(b,mid)<n1){
            l=mid+1;
        }else{
            cout<<mid;
            return 0;
        }
    }

    cout<<"Impossible"; 
}

