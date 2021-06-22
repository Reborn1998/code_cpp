#include<iostream>
using namespace std;
char return_operator(int a,int b,int c)
{
	if(a+b==c) return '+';
	else if(a-b==c) return '-';
	else if(a*b==c) return '*';
	else if(a/b==c) return '/';
    else return '0'; 
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		char ch1= return_operator(a,b,c);
		char ch2= return_operator(b,a,c);
		if(ch1!='0') cout << a << ch1 << b << "=" << c << endl;
		else if(ch2!='0') cout << b << ch2 << a << "=" << c << endl;
		else cout<<"None\n";
	}
}
