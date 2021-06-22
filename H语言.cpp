#include<iostream>
using namespace std;
char way[4]={'N','E','S','W'};
int ant=0,x,y;
void walk(int k){
	switch(k){
	    case 0:y++;break;
		case 1:x++;break;
		case 2:y--;break;
		case 3:x--;break;
		}
}
void fun(int a,int b){
   if(a<=0||b<=0) return;
       else {
       	walk(ant);
       	fun(a-b,b);
       	ant=(ant+1)%4;
       	fun(b-a,a);
	   }
}

int main(){
	int n,a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		x=y=0;
		ant=0;
		fun(a,b);
		cout<<x<<" "<<y<<" "<<way[ant]<<endl;
	}
}
