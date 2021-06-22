#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string ss;
	double SumTime;
	while(getline(cin,ss))
	{
		double time=0;
		for(int i=0;i<ss.length();i++)
		{
			ss[i] = toupper(ss[i]);
			if(ss[i]==' ') time += 0.5;
			else if(ss[i]>='A'&&ss[i]<='R')
			{
			    time += (ss[i]-'A'+1)%3 * 0.5+ (((ss[i]-'A'+1)%3)==0?1.5:0);
			    cout<<time<<"ss\n";
			}
			else if(ss[i]>'R'&&ss[i]<='Z')
			{
				if(ss[i]=='S'||ss[i]=='Z') time +=2;
				else if(ss[i]=='T'||ss[i]=='W') time +=0.5;
				else if(ss[i]=='U'||ss[i]=='X') time +=1;
				else time += 1.5;
			}
			else
			{
				time +=1;
			}
 		}
 		time++;
 		cout<<time<<endl;
 		SumTime +=time;
	}
} 


