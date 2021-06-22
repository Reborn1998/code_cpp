#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const string &s1,const string &s2)
{
	string a1,a2,a3,b1,b2,b3;
	a1 = s1.substr(0,2);b1 = s2.substr(0,2);
	a2 = s1.substr(3,2);b2 = s2.substr(3,2);
	a3 = s1.substr(6,4);b3 = s2.substr(6,4);
	if(a3!=b3) return a3<b3;
	else if(a2!=b2) return a2<b2;
	else return a1<b1; 
}
int main()
{
	vector<string> s;
	string m;
	while(cin>>m)
	{
		s.push_back(m);
	 } 
	 int len = s.size();
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<len;i++)
    {
    	cout << s[i] << endl; 
	}
 } 
