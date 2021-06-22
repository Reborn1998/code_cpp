#include<iostream>
using namespace std;
int main(){
	char ch;
	while((ch=getchar())!=EOF){		   
	    if(ch=='1') putchar('0');
		    else if(ch=='0') putchar('1');
	    cout<<endl;
	}
}
