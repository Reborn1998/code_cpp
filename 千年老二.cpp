#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;
int stoi(const string &s)              //string ת����int 
{
	int sum=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=' ') sum = sum*10+s[i]-'0'; 
	}
	return sum; 
}
int main()
{
	int grade[102]={0};
	string s;
	int n;
	while(getline(cin,s))
	{
		n=stoi(s.substr(0,3));              //��¼��һ���ɼ� 
		grade[n]++;
		for(int i=1;i<s.length();i++)
		{
			if(s[i]==' ') {                           //��¼ÿ���ո����ĳɼ�ת����������¼�ɼ����ִ��� 
				n=stoi(s.substr(i+1,3));
				grade[n]++;
			}
			
		}
		int cnt=0;
		for(int i=100;i>=0;i--)              //��߷��жϳ�����cnt=1������һ����Ч�ĳɼ����ǵڶ����ɼ� 
		{			
			if(cnt&&grade[i]) {
				cout<<i<<endl;
				break;
			}
			if(grade[i]) cnt = 1;
		}
	}
}
