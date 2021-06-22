#include<iostream>
using namespace std;

int main()
{
    int  n;
	while(cin>>n)
	{
	    int round = 0;
		for(int num=5;n>num;){
		    round++;
			n -= num;
			num <<= 1;			
	}	
	int t=(n-1)/(1<<round);
	if(t==0)cout<<"Sheldom\n";
	else if(t==1) cout<<"Leonard\n";
	else if(t==2) cout<<"Penny\n";
	else if(t==3) cout<<"Rajesh\n";
	else cout<<"Howard\n";
	}
} 
