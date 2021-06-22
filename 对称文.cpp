#include<iostream>
#include<string>
using namespace std;
bool isH(const string &s)
{
	int t=1;
	for(int i=0;i<s.length()/2;i++)
	{
		cout<<s[i]<<"  "<<endl;
		if(s[i]!=s[s.length()-1-i]){t=0; cout<<t<<"s";
		} 
		if(s[i]=='<'&&s[s.length()-1-i]=='>') t = 1;
		if(s[i]=='('&&s[s.length()-1-i]==')') {t = 1;cout<<t;
		}
		if(s[i]=='['&&s[s.length()-1-i]==']') t = 1;
		if(s[i]=='{'&&s[s.length()-1-i]=='}') t = 1;
		if(s[i]=='<'&&s[s.length()-1-i]=='<') t = 0;
		if(s[i]=='('&&s[s.length()-1-i]=='(') {
		t = 0;cout<<t;}
		if(s[i]=='['&&s[s.length()-1-i]=='[') t = 0;
		if(s[i]=='{'&&s[s.length()-1-i]=='{') t = 0;
		if(s[i]=='>'&&s[s.length()-1-i]=='>') t = 0;
		if(s[i]==')'&&s[s.length()-1-i]==')') t = 0;
		if(s[i]==']'&&s[s.length()-1-i]==']') t = 0;
		if(s[i]=='}'&&s[s.length()-1-i]=='}') t = 0;
	}
	return t;
}
void tolow( string &s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z') s[i] += 32;
	}
 } 
int main()
{
	string s;
	while(getline(cin,s))
	{
	//	if(!cin.get()) continue;
		if(s=="000000") break;
		tolow(s);
		cout<<s<<"    ***"<<endl; 
		if(isH(s)) cout<<"Symmetry\n";
		else cout<<"Not symetry\n";
	}
	
} 
