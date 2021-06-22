#include<iostream>
#include<string>
using namespace std;
int main(){
    int x,y,d;
    cin>>x>>y>>d;
    int sum = x + y;
    string str="";
    while(sum!=0){
        str = char(sum%d + '0') + str;
        sum = sum/d;
    }
    cout<<str;
}
