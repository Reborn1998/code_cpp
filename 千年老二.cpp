#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;
int stoi(const string &s)              //string 转换成int 
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
		n=stoi(s.substr(0,3));              //记录第一个成绩 
		grade[n]++;
		for(int i=1;i<s.length();i++)
		{
			if(s[i]==' ') {                           //记录每个空格后面的成绩转换出来并记录成绩出现次数 
				n=stoi(s.substr(i+1,3));
				grade[n]++;
			}
			
		}
		int cnt=0;
		for(int i=100;i>=0;i--)              //最高分判断出来后cnt=1，则下一个有效的成绩即是第二名成绩 
		{			
			if(cnt&&grade[i]) {
				cout<<i<<endl;
				break;
			}
			if(grade[i]) cnt = 1;
		}
	}
}
