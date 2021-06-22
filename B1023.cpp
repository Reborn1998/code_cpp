#include<iostream>
#include<string>
using namespace std;
int main(){
	int num[10];
	string str=""; 
	for(int i=0l;i<10;i++){
		cin>>num[i];
		for(int j=0;j<num[i];j++){
			str += char(i+'0');
		}
	}
	if(num[0]!=0){
		swap(str[0],str[num[0]]);
	}
	cout<<str;
}
