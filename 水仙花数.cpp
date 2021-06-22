#include<iostream>
using namespace std;
bool isS(int n)
{
	int a,b,c;
	a=n/100;
	b=n/10-a*10;
	c=n%10;
	if(a*a*a+b*b*b+c*c*c==n) return true;
	else return false;
}
int main()
{
	for(int i=100;i<1000;i++)
	{
	if(isS(i)) cout<<i<<endl;
	}

}
