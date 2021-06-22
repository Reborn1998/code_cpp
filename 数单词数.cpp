#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
struct dc
{
	string s;
	int cnt=1;
};
int main()
{
	string s;
	vector<dc> d;
	cin>>s;
	d[0].s = s;
	while(cin>>s)
	{
		int i;
		for(i=0;i<d.size();i++)
		{
		    if(d[i].s==s){
		    	d[i].cnt+=1;
		    	break;
			}	
		}
		if(i==d.size())
		{
			dc dd;
			dd.s=s;
			d.push_back(dd);
		}
	} 
	for(int i;i<d.size();i++)
	    cout<<d[i].s<<" "<<d[i].cnt<<endl;
	
}
