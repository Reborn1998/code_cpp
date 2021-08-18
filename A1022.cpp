#include<bits/stdc++.h>
using namespace std;
map<string, set<int> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;
void query(map<string,set<int> >& mp,string& str){
	if(mp.find(str)==mp.end()) printf("Not Found\n");
	else{
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	int n,m,id,type;
	string title,author,key,pub,year;
	scanf("%d",&n);
	for(int i=0;i<n;i++){	
		scanf("%d",&id);
		char c = getchar();
		getline(cin,title);   //the book title
		mpTitle[title].insert(id);
		getline(cin,author); //the author
		mpAuthor[author].insert(id);
		while(cin>>key){ //the key words
			mpKey[key].insert(id);
			char c = getchar();
			if(c=='\n') break;
		}
		getline(cin,pub); // the publisher
		mpPub[pub].insert(id);
		
		getline(cin,year);   //the published year
		mpYear[year].insert(id);
		
	}
	string temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,temp);
		cout<<type<<": "<<temp<<endl;
		if(type==1) query(mpTitle,temp); 
		else if(type==2) query(mpAuthor,temp); 
		else if(type==3) query(mpKey,temp); 
		else if(type==4) query(mpPub,temp); 
		else query(mpYear,temp);
	}
}
