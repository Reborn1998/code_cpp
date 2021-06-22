#include<iostream>
//#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	string s1[1000];
	char s2[1500];
	char b[100]; 
	char d[100];
	int c[1000]={0};
	int j,k;
    j=k=0;
	while(gets(s2)){	
	for(int i=0;i<strlen(s2);i++){
		
	if(s2[i]!=' '&&s2[i]!='.'){
	b[k]=s2[i];
	k++;} //存字符串 
  	
	  else if(s2[i]==' '||s2[i]=='.'){
		
		for(int n=0;n<=j;n++){
			if(s1[n]==b){
			c[n]++;
			break;}// 判断是否重复 
			
           if(n==j&&s1[j]!=b){
			j++;
	        s1[j]=b;// 输出字符串
	       } 
}           
           for(int z=0;z<k;z++)
			b[z]=d[z];
             k=0;//将中间变量变为空字符 
	}   
}}
double sum=0;
for(int i=1;i<=j;i++)
sum+=c[i];

string temp;
int p;
for( i=0;i<j-1;i++){
       for(int m=0;m<j-1-i;m++){
            if(s1[m]>s1[m+1])
			{temp=s1[m];
			s1[m]=s1[m+1];
			s1[m+1]=temp;
			p=c[m];
			c[m]=c[m+1];
			c[m+1]=p;}
			}}
			
for( i=1;i<=j;i++){
cout<<setw(15)<<setiosflags(ios::right)<<s1[i]<<": ";
cout<<setw(2)<<c[i]<<" ";
cout<<setw(5)<<setiosflags(ios::right)<<fixed<<setprecision(2)<<c[i]/sum*100;
cout<<"%"<<endl;
}
}
