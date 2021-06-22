#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
bool cmp(int a,int b) 
{
	return a>b;
}
int main()
{
	int n;
	vector<int> d[5];
	while(cin>>n)
	{
		if(n==0) break;
		int m;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			if(m<=100&&m>=90) d[0].push_back(m);
			if(m<=89&&m>=80)  d[1].push_back(m);
			if(m<=79&&m>=70)  d[2].push_back(m);
			if(m<=69&&m>=60)  d[3].push_back(m);
			if(m<60) d[4].push_back(m);
		}
		
		sort(d[0].begin(),d[0].end(),cmp);
		sort(d[1].begin(),d[1].end(),cmp);
		sort(d[2].begin(),d[2].end(),cmp);
		sort(d[3].begin(),d[3].end(),cmp);
		sort(d[4].begin(),d[4].end(),cmp);
		
		for(int i=0;i<5;i++)
		{
			cout<<char(65+i)<<":";
			for(int j=0;j<d[i].size();j++) cout<<setw(3)<<d[i][j];
			cout<<endl;
		}

	}
 } 
