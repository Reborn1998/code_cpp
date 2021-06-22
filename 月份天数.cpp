#include<iostream>
using namespace std;
bool isYear(int n)
{
	if((n%4==0&&n%100!=0)||(n%400==0)) return 1;
	else return 0;
}
int main()
{
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month;
    while(cin>>year>>month)
    {
    	if(month<1||month>12) cout<<"ERROR\n";
		else if(month==2) 
		{
			cout<<day[month]+isYear(year)<<endl;
		} 
		else cout<<day[month]<<endl;
	}
} 
