#include<iostream>
#include<cstring>
using namespace std;
char s[100005];
int main(){
	int k,n;
	cin >> k;
     n=k;
	cin >> s;
	for(int i=0; i<strlen(s); i++)
	{
		k=n;
		if(k+s[i]>122) k-=122-s[i],s[i]='a'+k-1;
        else s[i]=s[i]+k;
		;
	}
	

	cout << s << endl;
	return 0;
}	/*{
		s[i]+=k;
		if(s[i]>'z'){
		s[i]=s[i]-'z'+'a'; cout<<"s";}
	}*/
