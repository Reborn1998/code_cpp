#include<iostream>
#include<cmath>
#include<Vector>
using namespace std;
struct Point{
	int x,y;
	double d;
}; 
void dd(Point &a,Point &b)
{
	double m;
	m=(b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
	m = sqrt(m);
	b.d = m;
}

int main(){
	
	Point P,n;
	cin>>P.x>>P.y;	
	cin>>n.x>>n.y;
	dd(P,n);
	int min=n.d; 
	while(cin>>n.x>>n.y)
	{
		dd(P,n);
		if(n.d<min)  {
			P = n;
			min = n.d;
		}
	}
	cout<<P.x<<" "<<P.y<<endl; 
}
