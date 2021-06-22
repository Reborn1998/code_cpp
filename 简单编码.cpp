#include<iostream>
#include<string>
using namespace std;
char bm(char c)
{
	if(c=='A'||c=='W'||c=='F') return 'I';
	else if(c=='C')  return 'L';
	else if(c=='M') return 'o';
	else if(c=='S') return 'v';
	else if(c=='L') return 'Y';
	else if(c=='X') return 'u';
	else if(c=='D'||c=='P'||c=='G'||c=='B') return 'e';
	else return c;
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		if(s=="END") break;
		for(int i=0;i<s.length();i++)
		{
		    cout<<bm(s[i]);
		}
		cout<<endl;
	}
}
