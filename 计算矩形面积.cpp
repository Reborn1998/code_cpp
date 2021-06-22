#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<double> S;
	int a,b,x,y;
	double s;
	while(cin>>a>>b>>x>>y)
	{
		s = (y-b)*(x-a);
		if(s<0) s = -s; 
		S.push_back(s);
	}
	sort(S.begin(),S.end());
	for(int i=0;i<S.size();i++)
	    cout<<S[i]<<endl;
}
