#include<iostream>
#include<vector>
#include<string>
using namespace std;
void toupper(string &s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='z'&&s[i]>='a') s[i] -= 32;
	}
}
int main()
{
	string s;
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		
		getline(cin,s);
		
		vector<string> vab;
		int len=s.size();
		s[len] = ' ';
		s[len+1] = '\0';
		for(int i=0;i<s.size();)
		{
			for(int j=i+1;;j++)
			{
				string v;
				if(s[j]==' ') 
				{
					v = s.substr(i,j-i);
					toupper(v);
					i=j+1;
					vab.push_back(v);
					break;
				 } 
			}
		}
		for(int i=0;i<vab.size();i++) 
		{
			if(vab[i]=="AND"||vab[i]=="FOR"||vab[i]=="THE"||vab[i].length()<3) continue;
			cout<<vab[i][0]; 
		} 
		cout<<endl;
	}
}
