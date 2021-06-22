#include<iostream>
using namespace std;
int main(){
    int n;
    char c;
    cin>>n>>c;
    int rol = n % 2 + n / 2;
    for(int i=0;i<rol;i++){
        for(int j=0;j<n;j++){
            if(i>0 and i<rol-1 and j>0 and j<n-1){
                cout<<' ';
            }else{
                cout<<c;
            }
            
        }
        cout<<"\n";
    }
}
