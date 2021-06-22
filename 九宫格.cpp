#include<iostream>
using namespace std;
bool isCorrect(int (*num)[3])
{
	int b=1;
	int sum = num[0][0]+num[1][1]+num[2][2];
	for(int i=0;i<3;i++)
	{
		if(num[i][0]+num[i][1]+num[i][2]!=sum) b=0;
		if(num[0][i]+num[1][i]+num[2][i]!=sum) b=0;
	}
	
	if(num[0][2]+num[1][1]+num[2][0]!=sum) b=0;
	return b;
}
int main()
{
	int t;
	int num[3][3]; 
	cin>>t;
	while(t--)
	{
		for(int i=0;i<3;i++)
		    for(int j=0;j<3;j++)
		        cin>>num[i][j];
		if(isCorrect(num)) cout<<"Cheers!"<<endl;
		else cout<<"OMyGa!"<<endl;
	}
}
