#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    int a[50][50],len,i,j;
    int k=0;
    while(cin>>len){
        k++;
        if(k>1) cout<<endl<<endl;
    //    先全部赋值为1
    for(i=0;i<50;i++)
        for(j=0;j<50;j++)
            a[i][j]=1;
    //    杨辉三角形计算
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            if(i>=1) a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
        a[i][i]=1; a[i][0]=1;
    }
    //    输出
    int count=0;
    for(i=0;i<len;i++){
        if(count>0) cout<<endl;
        count++;
        cout<<string(2*(len-i-1)+(len-i),' ');
        for(j=0;j<count;j++){
            cout<<setw(3)<<a[i][j];
        }
    }
        
    }
    
}
