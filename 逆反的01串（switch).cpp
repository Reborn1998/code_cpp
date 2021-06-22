#include<iostream>
using namespace std;
int main(){
	char ch;
	while((ch=getchar())!=EOF){
		switch(ch){
		case '1': putchar('0');break;
		case '0':putchar('1');break;
		default : cout<<endl;
		}
	}
}
