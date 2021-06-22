#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
	    char w[610];
		cin>>w;
		char a;
		int b=0,c,d;
		int len=strlen(w);
		a=w[0];
		for(int i=1;i<len;i++){
			if(w[i]=='.') b=i;
			if(w[i]=='E') c=i,d=i+1;
			
		}
		
		int n=0,m;
		
		for(int i=d+1;i<len;i++) if(w[i]!='0') n=w[i]-'0';
		
		if(a=='-') { cout<<"-";	}
			if(n==0)  {for(int i=1;w[i]!='E';i++) cout<<w[i];
			cout<<endl;continue;
			}

		if(w[d]=='+'){
			int i;
		     for(i=1;w[i]!='.';i++) cout<<w[i];
			 for(i=b+1;(w[i]!='E'&&i<=b+n);i++) cout<<w[i]; if(w[i]!='E')cout<<'.';
			 for(i=b+n+1;i<c;i++) cout<<w[i]; 
			 if(n>(c-b-1)) for(int i=0;i<(n-c+b+1);i++) cout<<'0';	
			 cout<<endl;
			
		}
		else if(w[d]=='-'){
			if(n<(b-1)) {
			    for(int i=1;i<(b-n);i++) cout<<w[i];
			    cout<<'.';strcpy(w+b,w+b+1);
				for(int i=(b-n);w[i]!='E';i++) cout<<w[i];
				cout<<endl;
				}
				else if(n==(b-1)) {
					
					cout<<"0.";
					strcpy(w+b,w+b+1);
					for(int i=1;w[i]!='E';i++) cout<<w[i];
                    cout<<endl;				
				}
				else if(n>(b-1)){
				    strcpy(w+b,w+b+1);
					cout<<"0.";
					for(int i=0;i<(n-b+1);i++)cout<<'0';
					for(int i=1;w[i]!='E';i++) cout<<w[i];
					cout<<endl;
				}
		}
		
		
   	}
}
       /* char w[40];
		cin>>w;
		char a;
		int b,c,d;
		double m=0;
		int len=strlen(w);
		a=w[0];
		for(int i=1;i<len;i++){
			if(w[i]=='.') b=i;
			if(w[i]=='E') c=i,d=i+1;
			
		}
		int n,x;
		
	    
		for(int i=d+1;i<len;i++) if(w[i]!='0') n=w[i]-'0';
		
		if(a=='-') { cout<<"-";	}
		for(int i=1;w[i]!='E';i++) {
			m=m*10+w[i]-'0';
		} 
		for(int i=b+1;w[i]!='E';i++) {
			m=m*10+w[i]-'0';
		}
		x=c-b-c+n;
		if(x=0)
		cout<<m<<endl;
		else if(x>0){
			for(int i=0;i<x;i++) m*=10;
			cout<<m<endl;
		}
		else if(x<0){
			x=-x;
			for(int i=0;i<x;i++) m/=10;
		}
	}
}
    */
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
