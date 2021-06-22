#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
string toupper(string s)
{
	for(int i=0;i<s.size();i++)
	    if(s[i]>='a'&&s[i]<='z') s[i]-32;
	return s;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<string> ss;
		string s;
		while(getline(cin,s)) 
		{
			if(!cin.get()) break;
			s=s+" ";
			
			for(int i=0;i<s.length();)
			{
			    cout<<"ss"<<i;
				string sub;
				for(int j=i+1;j<s.length()+1;j++)
				{
					if(s[j]==' ')
					{
						sub=s.substr(i,j-i);
						ss.push_back(sub);
						i=j+1;
					} 
				}
			}
		
		    for(int i=0;i<ss.size();i++)
		    {
	    		string ch;
	    		if(ss[i].size()<3) continue;
	    		ch = toupper(ss[i]);
	    		if(ch=="THE"||ch=="AND"||ch=="FOR") continue;
	    		cout<<toupper(ss[i][0]);
	    	} 
		}
	}
 } 
