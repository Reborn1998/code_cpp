#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    string temp;
    char str[90][90];
    int num = 0;
    getline(cin,temp);
    int k=0;
    for(int i=0;i<temp.length();i++){
    	if(temp[i]!=' '){
    		str[num][k++] = temp[i]; 	
		}else{
			str[num][k]='\0';
			num++;
			k=0;
		}
	}
	str[num][k]='\0';
    for(int i=num;i>=0;i--){
        if(i!=num) cout<<" ";
        printf("%s",str[i]);
    }
}
