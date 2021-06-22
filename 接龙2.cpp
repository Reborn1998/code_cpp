#include<iostream>
#include<cstring>
using namespace std;
int main (){
	char s2[4],s1[20]; 
	while(cin >> s1 >> s2){
	int n;
	n=strlen(s1);
    if(s1[0]=='1'&&s1[1]=='0')s1[1]='1'; 
    if(s1[n-2]=='1'&&s1[n-1]=='0')s1[n-1]='1';
	switch (s2[0]){
	case 'A':if(s1[0]=='2')cout << "Yes\n";
	         else cout << "No\n";
			 break;
	case '2':if(s1[0]=='3'||s1[n-1]=='A') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
    case'3': if(s1[0]=='4'||s1[n-1]=='2') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'4':if(s1[0]=='5'||s1[n-1]=='3') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'5':if(s1[0]=='6'||s1[n-1]=='4') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'6':if(s1[0]=='7'||s1[n-1]=='5') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
    case'7':if(s1[0]=='8'||s1[n-1]=='6') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'8':if(s1[0]=='9'||s1[n-1]=='7') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'9':if(s1[0]=='8'||s1[n-1]=='1') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'1':if(s1[0]=='J'||s1[n-1]=='9') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'J':if(s1[0]=='Q'||s1[n-1]=='1') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'Q':if(s1[0]=='K'||s1[n-1]=='J') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
	case'K':if(s1[n-1]=='Q') cout <<"Yes\n"; 
	         else cout << "No\n";
			 break;
    
	}


	}


return 0;
}

