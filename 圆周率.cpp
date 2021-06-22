#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
long double R[400000];
void round(int n)
{
	long double pai=1;
	R[0] = 1;
	for(int i=0;i<n;i++)
	{
		pai = pai + pow(double(-1),i+1)/(2*i+3);
		R[i+1] = 4*pai; 
	}
	
}
int main()
{
    int n;
    long double pai;
    round(400000);
	while(cin>>n)
	{	    
		if(n==0) break;
		
		cout << setiosflags(ios::fixed) << setprecision(8) << R[n] <<endl;
	}	
} 
