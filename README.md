# code_cpp

# 单词

**Invert**：反转

**corresponds to** ：符合

**indices**：指数

**seniority level**:级别水平

# 数学问题

## 1015 **Reversible Primes**

* 输入结束
* 题意素数经过进制转换再倒转继续转回十进制后还是素数

```c++
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n,d;
	while(scanf("%d",&n)!=EOF){
		if(n<0)break;
		scanf("%d",&d);
		if(isPrime(n)==false){
			printf("No\n");
		}else{
			int len = 0;
			int sum=0;
			while(n!=0){
				int i=n%d;
				n/=d;
				sum = sum*d+i;
			}
			if(isPrime(sum)) printf("Yes\n");
			else printf("No\n");
		}
	}
}
```

## 1023 **Have Fun with Numbers**

*  大整数乘以2后组成数字与原来相同

```c++
#include<bits/stdc++.h>
using namespace std;
int numA[50];
int numB[50];
string doubleA(string a){
	for(int i=0;i<a.size();i++){
		numA[i] = a[a.size()-1-i]-'0';
		numB[i] = numA[i]*2;
	}
	string b="";
	for(int i=0;i<a.size();i++){
		if(numB[i]>9){
			numB[i+1] += numB[i]/10;
			numB[i] = numB[i]%10;
		}
		b+= '0'+numB[i];
	}
	if(numB[a.size()]!=0 ) b+='0'+numB[a.size()];
//	cout<<"A:";
//	for(int i=0;i<a.size();i++){
//		cout<<numA[i]<<" ";
//	}
//	cout<<"\nB:";
//	for(int i=0;i<b.size();i++){
//		cout<<numB[i]<<" ";
//	}
	return b;
}
int main(){
	string a;
	cin>>a;
	string b;
	b = doubleA(a);
	if(a.size()!=b.size()){
		cout<<"No\n";
	}else{
		int n = a.size();
		sort(numA,numA+n);
		sort(numB,numB+n);
		int i=0;
		for(;i<n;i++){
			if(numA[i]!=numB[i]) {
				cout<<"No\n";
				break;
			}
		}
		if(i==n) cout<<"Yes\n";
	}
	reverse(b.begin(),b.end());
	cout<<b;
}
```

## 1024**Palindromic Number**

* 法一:string直接做加法
* 法二：转成数组做，注意用g++不能用clang++

```c++
#include<bits/stdc++.h>
using namespace std;
string s;
void add(string t){
	int flag = 0;
	for(int i=t.size()-1;i>=0;i--){
		s[i] = s[i]+t[i]+flag-'0';
		flag=0;
		if(s[i]>'9'){
			s[i] -= 10;
			flag = 1;
		}
	}
	if(flag) s = '1'+s;
}
int main(){
	int k,i;
	cin>>s>>k;
	for(i=0;i<k;i++){
		string t=s;
		reverse(t.begin(),t.end());
		if(s==t||i==k)break;
		add(t);
	}
	cout<<s<<endl<<i;
}
//int num1[1000];
//int num2[1000];
//int num[1000];
//int len;
//void init(string a){
//	len = a.size();
//	for(int i=0;i<a.size();i++){
//		num[i] = a[a.size()-i-1]-'0';
//	}
//}
//bool judge(){
//	for(int i=0;i<len;i++){
//		if(num1[i]!=num2[i]){
//			return false;
//		}
//	}
//	return true;
//}
//void change12(){
//	for(int i=0;i<len;i++){
//		num1[i] = num[i];
//		num2[i] = num[len-1-i];
//	}
////	cout<<"===============\n";
////	for(int i=0;i<len;i++)cout<<num1[len-i-1];
////	cout<<endl;
////	for(int i=0;i<len;i++)cout<<num2[len-i-1];
////	cout<<endl;
////	cout<<"======1111=====\n";
//}
//void add(){
//	for(int i=0;i<len;i++){
//		num[i] = num1[i]+num2[i];
//		if(num[i]>9){
//			num1[i+1] += num[i]/10;
//			num[i] = num[i]%10;
//		}
//	}
//	if(num1[len]!=0) num[len] = num1[len++];
//}
//int main(){
//	string a;
//	int k;
//	cin>>a>>k;
//	int cnt=1;
//	init(a);
//	for(;cnt<=k;cnt++){	
//		change12();
//		if(judge()){
//			for(int i=1;i<=len;i++){
//				cout<<num[len-i];
//			}
//			cout<<endl;
//			cout<<cnt-1;
//			return 0;
//		}
//		
//		add();
//	}
//	for(int i=1;i<=len;i++){
//		cout<<num[len-i];
//	}
//	cout<<endl;
//	cout<<k;
//}
```

## 1039 **Course List for Student**（字符串hash作为唯一标记）

* 名字转换成唯一编号， hash 26\*26\*26\*10+1
* 别用string cin cout map

```c++
#include<bits/stdc++.h>
using namespace std;
const int M = 26*26*26*10+1;
vector<int> v[M];
int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id = id*26+(name[i]-'A');
	}
	id = id*10+(name[3]-'0');
	return id;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	char name[5];
	for(int i=0;i<k;i++){
		int course,x;
		scanf("%d%d",&course,&x);
		for(int j=0;j<x;j++){
			scanf("%s",name);
			int id = getID(name);
			v[id].push_back(course);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",name);
		int id = getID(name);
		sort(v[id].begin(),v[id].end());
		printf("%s %d",name,v[id].size());
		for(int j=0;j<v[id].size();j++){
			printf(" %d",v[id][j]);
		}
		printf("\n");
	}
}
```

## 1047**Student List for Course**

* 忘记写ruturn会出行段错误，剩余注意点同1039

```c++
#include<bits/stdc++.h>
using namespace std;
int getID(char name[]){
	int id= 0;
	for(int i=0;i<3;i++){
		id = id*26+(name[i]-'A');
	}
	id = id*10+(name[3]-'0');
	return id;
}
void getName(int id,char name[]){
	int num[4];
	num[0] = id%10;
	id/=10;
	for(int i=1;i<=3;i++){
		num[i] = id%26;
		id = id/26;
	}

	for(int i=3;i>0;i--){
		name[3-i] = 'A' + num[i]; 

	}

	name[3] = '0'+num[0];
	name[4] = '\0';


}
bool cmp(int a,int b){
	char ma[5];
	getName(a,ma);
	char mb[5];
	getName(b,mb);
	return strcmp(ma,mb)<0;
}
const int maxn = 40010;
char name[maxn][5];
const int maxc = 2510;
vector<int> course[maxc];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	char name[5];
	int num;
	for(int i=0;i<n;i++){
		
		scanf("%s %d",name,&num);
		int id = getID(name);
		for(int j=0;j<num;j++){
			int c;
			scanf("%d",&c);
			course[c].push_back(id);
		}
		
	}

	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++){
			getName(course[i][j],name);
			printf("%s\n",name);
		}
	}
	
}
```



## 1049 count one

* XXXX1,记录XXXX有几种情况，XXX1？记录XXX有几种情况

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a=1,ans=0;
	int left,now,right;
	scanf("%d",n);
	while(n/a!=0){
		left = n/(a*10);
		now = n/a%10;
		right=n%a;
		if(now==0) ans+=left*a;
		else if(now ==1) ans+=left*a+right+1;
		else ans +=(left+1)*a;
		a*=10;
	}
	printf("%d",ans);
} 
```

## 1069 **Set Similarity**

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=52;
set<int> st[N]; 
void compare(int x,int y){
	int total = st[y].size(),same=0;
	for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++){
		if(st[y].find(*it)!=st[y].end()) same++;
		else total++;
	}
	printf("%.1f%%\n",same*100.0/total);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m,a;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&a);
			st[i].insert(a);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		compare(x,y);
	}
}
```



## 1078 **Hashing**

* 二次方探测法！！

```c++
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int table[11111];
int main(){
	int ms,n;
	scanf("%d %d",&ms,&n);
	int ts=ms;
	while(!isPrime(ts)) ts++;
	int a,idx;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		idx = a%ts;
		if(table[idx]==0) {
			printf("%d",idx);
			table[idx]=1;
		}
		else{
			int step=1;
			for(;step<ts;step++){
				idx = (a+step*step)%ts;
				if(table[idx]==0) {
					printf("%d",idx);
					table[idx]=1;
					break;
				}
			}
			if(step==ts)
			printf("-");
		}
		if(i!=n-1) printf(" ");
	}
}
```



##  1081 Rational Sum

* 分子为0要注意
* 避免除0操作
* 数据类型long long 
* 输出格式

```c++
#include<bits/stdc++.h>
using namespace std;
long long  gcd(long a,long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

struct Fraction{
	long long up,down;
};
Fraction reduction(Fraction result){
	
}
Fraction add(Fraction a,Fraction b){
	Fraction result;
	long long x = a.up*b.down+b.up*a.down;
	long long y = a.down*b.down;

		
	long long g = gcd(abs(x),abs(y));
	if(y<0) x=-x,y=-y;
	if(x==0){
		result.up = 0;
		result.down = 1;
	}else{
		result.up = x/(g?g:1);
		result.down = y/(g?g:1);
	}
	return result;
}
int main(){
	int n;
	scanf("%d",&n);
	Fraction a,b;
	a.up=0;
	a.down=1;
	for(int i=0;i<n;i++){	
		scanf("%lld/%lld",&b.up,&b.down);
		a  = add(a,b);
//		cout<<a.up<<" "<<a.down<<endl;
	}
	
	int x = a.up/a.down;
	a.up -= (a.up<0?-1:1)*a.down*x; 
	if(x!=0){
		printf("%d",x);
		if(a.up!=0) printf(" ");
		a.up = abs(a.up);
	}
	if(a.up!=0 && a.down!=1){
		printf("%lld/%lld",a.up,a.down);
	}else if(x==0){
		printf("0");
	}
}
```

## 1088(**Rational Arithmetic**)

```c++
#include<bits/stdc++.h>
using namespace std;
struct Fraction{
	long long up,down;
}a,b;
long long gcd(long long a,long long b){
	return b==0? a:gcd(b,a%b);
}
Fraction reduction(Fraction s){
	if(s.down<0){
		s.down = -s.down;
		s.up = -s.up;
	}
	if(s.up==0){
		s.down = 1;
	}else{
		int d = gcd(abs(s.up),abs(s.down));
		s.up /= d;
		s.down /= d;
	}
	return s;
}
Fraction add(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down+x.down*y.up;
	ans.down = x.down * y.down;
	return reduction(ans); 
}
Fraction sub(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down-x.down*y.up;
	ans.down = x.down * y.down;
	return reduction(ans) ;
}
Fraction mul(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.up;
	ans.down = x.down * y.down;
	return reduction(ans) ;
}
Fraction divide(Fraction x,Fraction y){
	Fraction ans;
	ans.up = x.up*y.down;
	ans.down = x.down * y.up;
	return reduction(ans) ;
}
void showResult(Fraction r){
//	cout<<r.up<<"/"<<r.down<<endl;
	r = reduction(r);
//	cout<<r.up<<"/"<<r.down<<endl;
	if(r.up<0) printf("(");
	if(r.down==1) printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%lld/%lld",r.up,r.down);
	}
	if(r.up<0) printf(")");
}
int main(){
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);

	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n");
	
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a,b));
	printf("\n");
	
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(mul(a,b));
	printf("\n");
	
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up==0) printf("Inf");
	else 	showResult(divide(a,b));
	printf("\n");
} 
```



## 1093（count PAT）

* 取模
* 可以倒着算T的数量到A后乘以P的数量避免用数组记T的个数

```c++
#include<iostream>
using namespace std;
const int maxn=100010;
long long  numP[maxn]={0};
long long numT[maxn]={0};
int main(){
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i-1]=='P'){
			numP[i]=numP[i-1]+1;
		}
		else
			numP[i]=numP[i-1];
	}
	for(int i=s.size()-2;i>0;i--){
		if(s[i+1]=='T')
			numT[i] = numT[i+1]+1;
		else
			numT[i] = numT[i+1];
	}
	long long  sum = 0;
	for(int i=1;i<s.size();i++ ){
		if(s[i]=='A'){
			sum=(sum + numP[i]*numT[i])%1000000007;
		}
	}
	cout<<sum<<endl;
}
```

## 1069数字黑洞

* 输出格式

```c++
#include<bits/stdc++.h>
using namespace std;
int num[4];
void init(int last){
	for(int i=0;i<4;i++,last/=10){
		num[i] = last%10;
	}
}
int tmax(){
	int sum=0;
	for(int i=3;i>=0;i--){
		sum=sum*10+num[i];
	}
	return sum;
}
int tmin(){
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int Max,Min;
	int last;
	init(n);
	sort(num,num+4);
	Max=tmax();
	Min = tmin();		
	last=Max-Min;
	printf("%04d - %04d = %04d",Max,Min,last);
	while(true){	
		init(last);
		sort(num,num+4);
		Max=tmax();
		Min = tmin();	
		if(last!=Max-Min) {
			printf("\n");
			last =Max-Min;
		}
		else break;	
		printf("%04d - %04d = %04d",Max,Min,last); 		
	}
}
```

## 1104(数列的片段和)

* 测试点2需要long long形式的sum计算扩大1000倍的数据在除以1000.00输出 减小误差

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
double num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&num[i]);
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=(long long )(num[i]*1000*(n-i)*(i+1));
	}
	printf("%.2lf",sum/1000.00);
} 
```

## 1096 **Consecutive Factors**

* 可能不存在因数，
* 注意循环停止条件，sum也是n

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long sum=1;
	int ansL=0,ans;
	int tempL=0,temp;
	scanf("%lld",&n);
	for(int i=2;i*i<=n;i++){
		int j=i;
        sum=1;
		while(n%j==0){
			sum*=j;
			if(sum>n||n%sum!=0) break;
			if(j-i+1>ansL){
				ansL=j-i+1;
				ans=i;
			}
			j++;
			
		}			
	}
	if(ansL==0) printf("1\n%lld",n);
	else{
		printf("%d\n",ansL);
		for(int i=0;i<ansL;i++){
			printf("%d",ans++);
			if(i!=ansL-1) printf("*");
		}
	}
}
```

# STL

## Map

### A1054

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	map<int,int> count;
	int col;
	for(int i=0;i<n*m;i++){
		scanf("%d",&col);
		if(count.find(col)!=count.end()) count[col]++;
		else count[col] = 1;
	}
	int k=0,Max=0;
	for(map<int,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>Max){
			k=it->first;
			Max=it->second;
		}
	}
	printf("%d",k);
}
```

### 1071 **Speech Patterns**

```c++
#include<bits/stdc++.h>
using namespace std;
bool check(char c){
	if(c>='0'&&c<='9') return true;
	if(c>='A'&&c<='Z') return true;
	if(c>='a'&&c<='z') return true;
	return false;
}
int main(){
	map<string,int> count;
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.size()){
		string word;
		while(i<str.size()&&check(str[i])){
			if(str[i]>='A'&&str[i]<='Z'){
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word!=""){
			if(count.find(word)==count.end()) count[word] = 1;
			else count[word]++;
		}
		while(i<str.size()&&!check(str[i])){
			i++;
		}
	}
	string ans;
	int Max=0;
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>Max){
			ans = it->first;
			Max = it->second; 
		}
	}
	cout<<ans<<" "<<Max;
} 
```

### 1022 **Digital Library**

```c++
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
```

## stack

### 1051 **Pop Sequence**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
int main(){
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	while(t--){
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		int cur=1;
		for(int i=1;i<=n;i++){
//			cout<<i<<" s";
			st.push(i);
			
	
			if(st.size()>m){
//				cout<<"2";
				printf("No\n");
				break;
			}
			while(!st.empty()&&arr[cur]==st.top()){
//				cout<<"3";
				st.pop();
				cur++;
			}
			if(i==n&&!st.empty()&&arr[cur]!=st.top()){
//				cout<<"2";
				printf("No\n");
				break;
			}
				
		}
		if(st.empty()) printf("Yes\n");
	}
}
```

## List

* 静态链表排序，需要再Node中有个标志可以判断这个节点是否有效
* 一定要注意可能存在多条链表，不要的链表要考虑到如何不去管，记录有效的节点数

### 1032**Sharing**

* 用set记录链表一节点地址，遍历链表2查看是否再set中的节点

```c++
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;
    int next;
}node[100010];
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    for(int i=0;i<n;i++){
        int idx,next;
        char c;
        cin>>idx>>c>>next;
        node[idx].ch = c;
        node[idx].next = next;
    }
    set<int> s;
    while(a!=-1){
        s.insert(a);
        a = node[a].next;
    }
    while(b!=-1){
        set<int>::iterator it = s.find(b);
        if(it!=s.end()){
            printf("%05d",*it);
            return 0;
        }
        b = node[b].next;
    }
    
    cout<<"-1"<<endl;
}
```

### 1052 **Linked List Sorting**

```c++
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[100010];
bool cmp(Node a,Node b){
	if(!a.flag || !b.flag){
		return a.flag>b.flag;
	}
	return a.data<b.data;
}
int main(){
	for(int i=0;i<100010;i++){
		node[i].flag = false;
	}
	int n,head;
	scanf("%d%d",&n,&head);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		node[a].address = a;
		node[a].data = b;
		node[a].next = c;
	}
	int cnt = 0;
	int p = head;
	while(p!=-1){
		node[p].flag = true;
		cnt++;
		p = node[p].next;
	}
	if(cnt==0){
		printf("0 -1");
		return 0;
	}
	sort(node,node+100010,cmp);
	printf("%d %05d\n",cnt,node[0].address);
	for(int i=0;i<cnt;i++){
		if(i==cnt-1){
			node[i].next = -1;
			printf("%05d %d %d",node[i].address,node[i].data,-1);
		}else{
			node[i].next = node[i+1].address;
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i].next);
		}
		
	}
}
```



### 1074 **Reversing Linked List**

* 静态链表要会用，
* 注意链表长度不是n，排序时要重新记录下长度

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node{
	int address,data,next;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main(){
	for(int i=0;i<maxn;i++) node[i].order = maxn;
 	int start,n,k;
	scanf("%d%d%d",&start,&n,&k);
	for(int i=0;i<n;i++){
		int adr;
		scanf("%d",&adr);
		scanf("%d%d",&node[adr].data,&node[adr].next);
		node[adr].address = adr;
	}
	int cnt=1;
	for(int i=start;i!=-1;){
		node[i].order=cnt++;
		i = node[i].next;
	}
	sort(node,node+maxn,cmp);
	int i;
	n=cnt;
	for(i=0;i<n/k;i++){
		for(int j=0;j<k/2;j++){
			cout<<i*k+j<<":"<<node[i*k+j].data<<" "<<i*k+k-1-j<<":"<<node[i*k+k-j-1].data<<endl;
			swap(node[i*k+j],node[i*k+k-j-1]);
		}
	}
//	for(int j=0;j<(n%k)/2;j++){
//		cout<<i*k+j<<":"<<node[i*k+j].data<<" "<<i*k+k-1-j<<":"<<node[i*k+k-j-1].data<<endl;
//
//		swap(node[i*k+j],node[i*k+n%k-j-1]);
//	}
	for(int i=0;i<n;i++){
		printf("%05d %d ",node[i].address,node[i].data);
		if(i==n-1) printf("-1");
		else printf("%05d\n",node[i+1].address);
	}
}
```

### 1097 **Deduplication on a Linked Lis**

```
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
set<int> st;
struct Node{
	int adress,data,next;
	int flag;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag<b.flag;
	return a.order<b.order;
}
int main(){
	int start,n;
	scanf("%d%d",&start,&n);
	for(int i=0;i<maxn;i++){
		node[i].flag = 2*maxn;
		node[i].order = maxn;
	}
	
	
	for(int i=0;i<n;i++){
		int adr;
		scanf("%d",&adr);
		scanf("%d%d",&node[adr].data,&node[adr].next);
		node[adr].adress = adr;
		node[adr].flag=n+i;
//		if(st.find(abs(node[adr].data))!=st.end()){
//			node[adr].flag = cnt++;	
//		}else{
//			node[adr].flag = 0;
//			st.insert(abs(node[adr].data));
//		}
	}
	int p = start;
	int cnt=1;
	int k=0;
//	cout<<"=======================\n";
	while(p!=-1){
		node[p].order = k++;
		if(st.find(abs(node[p].data))!=st.end()){
			node[p].flag = cnt++;	
		}else{
			node[p].flag = 0;
			st.insert(abs(node[p].data));
		}
//		cout<<node[p].adress<<" "<<node[p].data<<" "<<node[p].flag<<" "<<node[p].order<<endl;
		p = node[p].next;	
	}
	cnt--;
	sort(node,node+maxn,cmp);
	p=start;
//	cout<<"=======================\n";
//	for(int j=0;j<n;j++){
//		
//		cout<<node[j].adress<<" "<<node[j].data<<" "<<node[j].flag<<" "<<node[j].order<<endl;	
//	}
//	cout<<"=======================\n";
	for(int i=0;i<k-cnt;i++){
		if(i!=k-cnt-1){
			printf("%05d %d %05d\n",node[i].adress,node[i].data,node[i+1].adress);
		}else{
			printf("%05d %d -1\n",node[i].adress,node[i].data);
		}
	}
	for(int i=k-cnt;i<k;i++){
		if(i!=k-1){
			printf("%05d %d %05d\n",node[i].adress,node[i].data,node[i+1].adress);
		}else{
			printf("%05d %d -1",node[i].adress,node[i].data);
		}
	}
} 
```



# 双指针

## A1085(完美数列)

* 注意数据大小可能超过int

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long  num[maxn];
int main(){
    long long n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    int idx=0,idx1=0;
    int mcnt = 0;
    for(;idx1<n;idx++){
    	while(num[idx1]<=p*num[idx]) {
    		idx1++;
    		if(idx1==n){
    			break;
			}
		}
    	if(idx1-idx>mcnt&&num[idx1-1]<=p*num[idx]) mcnt = idx1-idx;
	}
    cout<<mcnt;
}

```

## 1089(Merge or Insert)

* <=
* 也可以通过判断有序数列后的数列是否相同来判断排序方式

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;
int n;
int origin[maxn],tempOri[maxn];
int changed[maxn];
bool judge(int l,int r){
	for(int i=l;i<r;i++){
		
		if(changed[i]<changed[i-1]&&(i-l)%n!=0){
			return false;
		}
	}
	return true;
}
int main(){
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&origin[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&changed[i]);
	}
	int i=0,cnt=1;
	int flag=2;
	for(;i<n-1;i++){
		if(i+1<n){
//			cout<<changed[i]<<" "<<changed[i+1]<<endl;
			if(changed[i]<=changed[i+1]) cnt++;
			else {
				if(cnt==1) flag=0;
				v.push_back(cnt);
				cnt=1;
			}
		}
	}
//	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
//	}
//	cout<<endl;
	int m = v[0];	
	if(v.size()>2){
		sort(v.begin(),v.end());
		if(v[v.size()-1]%v[1]!=0) flag=0;
	}
	if(flag){
		sort(v.begin(),v.end());
		int group=v[0];
		int i=0;
		for(;i+2*group<n;i+=2*group){
			sort(changed+i,changed+i+2*group);
		}
		sort(changed+i,changed+n);
//		sort(changed,changed+n);
		cout<<"Merge Sort\n";
		for(i=0;i<n;i++){
			cout<<changed[i];
			if(i!=n-1) cout<<" ";
		}
	}
	else{
		
		sort(changed,changed+m+1); 
		cout<<"Insertion Sort\n";
		for(i=0;i<n;i++){
			cout<<changed[i];
			if(i!=n-1) cout<<" ";
		}
	}
}
```



# 二分查找

## 1010 Radix（进制）

* 上限和下限设置和二分查找可以减少时间
* 数据类型LL

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
string num[maxn];
long long  transform(string a,int r){
    long long sum=0;
    int n = a.size()-1;
    for(int i=0;i<a.size();i++){
        int x;
        if(a[i]>='a'&&a[i]<='z') x = a[i]-'a'+10;
        else x = a[i] - '0';
        sum = sum*r + x;
    }
    return sum;
}
int main(){
    string a,b;
    int tag,radix;
    cin>>a>>b>>tag>>radix;
    if(tag==2) swap(a,b);
    long long n1 = transform(a,radix);
    int maxr=0;
    for(int i=0;i<b.size();i++){
        int x;
        if(b[i]>='a'&&b[i]<='z') x = b[i]-'a'+10;
        else if(b[i]>='0'&&b[i]<='9') x = b[i] - '0';
        if(x>maxr) maxr = x;
    }
    int i;
    long long l,r,mid;
    l=maxr+1,r=max(l,n1+1);

    while(l<=r){
        mid = (l+r)/2;
         if(transform(b,mid)>n1||transform(b,mid)<0){
            r=mid-1;
        }
        else if(transform(b,mid)<n1){
            l=mid+1;
        }else{
            cout<<mid;
            return 0;
        }
    }

    cout<<"Impossible"; 
}

```



## A1085（完美数列)

* upper_bound(起始位置，结束位置，x)查找第一个大于x的数，减去首地址获得下标

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long  num[maxn];
long long n,p;
int binarySearch(int i,long long x){
	if(num[n-1]<x) return n;
	int l=i+1,r=n-1;
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(num[mid]<=x) l = mid+1;
		else if(num[mid]>x) r=mid;
	}
	return l;
}
int main(){

    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
	int idx=0;
	int i=0;
	int cnt=1;
	while(idx<n){
		idx = binarySearch(i,num[i]*p);//idx = upper_bound(num+i+1,num+n,num[i]*p)-num
		if(idx-i>cnt) cnt=idx-i;
		i++;
	}
	cout<<cnt;
}

```

## 1044(Shopping in Mars)

* 存储sum[i]为1-i的和，之后查找m+sum[i-1]在【i，n+1）区间
* 第一轮查最接近的，第二轮输出结果

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int num[maxn];
int sum[maxn]={0};
int bsearch(int l,int r,int target){
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(sum[mid]<=target){
			l=mid+1;
		}else if(sum[mid]>target){
			r=mid;
		}
	}
	return l;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	int near=1000000010;
	for(int i=1;i<=n;i++){
		int idx = bsearch(i,n+1,m+sum[i-1]); 

		if(sum[idx-1]-sum[i-1]==m){
			near=m;
			break;
		}else if(idx<=n&&sum[idx]-sum[i-1]<near){
			near = sum[idx]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int idx = bsearch(i,n+1,near+sum[i-1]); 
		if(sum[idx-1]-sum[i-1]==near){
			printf("%d-%d\n",i,idx-1);
		}
	}
}
```

# DFS

## A1103

```c++
#include<bits/stdc++.h>
using namespace std;
int n,k,p;
vector<int>temp;
vector<int>ans;
vector<int>fac;
int Max=-1;
int power(int x){
	int a=1;
	for(int i=0;i<p;i++){
		a*=x;
	}
	return a;
}
void init(){
	for(int i=0;power(i)<=n;i++){
		fac.push_back(power(i));
	}
}
void DFS(int idx,int now,int sum,int facSum){	
	
	if(sum==n&&now==k){
		
		if(facSum>Max){
			ans = temp;
			Max = facSum;
		}
		return;
	}
	if(sum>n||now>k) return;
	if(idx-1>=0){
		temp.push_back(idx);
		DFS(idx,now+1,sum+fac[idx],facSum+idx);
		temp.pop_back();
		DFS(idx-1,now,sum,facSum);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(Max==-1) printf("Impossible");
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
}
```

# BFS



## 1091**Acute Stroke**

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m,l,t;
int sum=0;
struct Node{
	int x,y,z;
}node;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
	if(x>=n||x<0||y>=m ||y<0 ||z>=l||z<0 ) return false;
	if(pixel[x][y][z]==0||inq[x][y][z]) return false;
	return true;
}
int BFS(int x,int y,int z){
	int tot = 0;
	queue<Node> q;
	node.x=x;node.y=y;node.z=z;
	q.push(node);
	inq[x][y][z]=true;
	while(!q.empty()){
		Node temp = q.front();
		q.pop();
		tot++;
		for(int i =0;i<6;i++){
			node.x = temp.x+X[i];node.y = temp.y+Y[i];node.z = temp.z+Z[i];
			if(judge(node.x,node.y,node.z)){
				inq[node.x][node.y][node.z]=true;
				q.push(node);
			}	
		}
	}
	if(tot>=t) return tot;
	return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&t);
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(pixel[x][y][z]==1&&!inq[x][y][z]){
					ans+=BFS(x,y,z);		
				}
			}
		}
	}
	printf("%d",ans);
} 
```



# 二叉树

## 1020**Tree Traversals(通过前序后序获得二叉树)**

```c++
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
int pre[33],in[33],post[33];
int n; 
Node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;
	}
	Node* root = new Node();
	root->data = post[postR];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==post[postR]) break;
	}
	int l = i-inL;
	root->left = create(postL,postL+l-1,inL,i-1);
	root->right = create(postL+l,postR-1,i+1,inR);
	return root;
}
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		printf("%d",temp->data);
		num++;
		if(num!=n) printf(" ");
		if(temp->left!=NULL) q.push(temp->left);
		if(temp->right!=NULL) q.push(temp->right);
	}
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	Node *root=create(0,n-1,0,n-1);
	BFS(root);
	
} 
```

## 1086**Tree Traversals Again(前序中序获得二叉树)**

```c++
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* lc;
	Node* rc;
	Node* father;
};
int pre[33],in[33],post[33];
int n;
Node* create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	Node* root = new Node();
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(pre[preL]==in[k]) break;
	}
	int l=k-inL;
	root->lc = create(preL+1,preL+l,inL,k-1);
	root->rc = create(preL+1+l,preR,k+1,inR);
	return root;
}
int num=0;
void postS(Node *root){
	if(root->lc!=NULL) postS(root->lc);
	if(root->rc!=NULL) postS(root->rc);
	printf("%d",root->data);
	if(num!=n-1) printf(" ");
	num++;
}
int main(){
//	1 2 3 4 5 6
//	3 2 4 1 6 5
	scanf("%d",&n);
	stack<int> st;
	int idp = 0,idi=0;
	string str;
	int d;
	for(int i=0;i<n*2;i++){
		cin>>str;
		if(str=="Push"){
			cin>>d;
			pre[idp++]=d;
			st.push(d);
		}
		if(str=="Pop"){
			in[idi++]=st.top();
			st.pop();
		}
	}
	Node *root = create(0,n-1,0,n-1);
	postS(root);
} 
```

## 1102**Invert a Binary Tree**

* 题目直接给的是节点编号关系，用静态链表

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n;
struct Node{
	int lc;
	int rc;
};
Node nodes[maxn];
int inq[maxn];
int pn=0;
void change(int x){
	swap(nodes[x].lc,nodes[x].rc);
	if(nodes[x].lc!=-1) change(nodes[x].lc);
	if(nodes[x].rc!=-1) change(nodes[x].rc);
}
void inorder(int x){
	if(nodes[x].lc!=-1) inorder(nodes[x].lc);
	printf("%d",x);
	pn++;
	if(pn!=n) printf(" ");
	if(nodes[x].rc!=-1) inorder(nodes[x].rc);
}
int bn=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		printf("%d",temp);
		bn++;
		if(bn!=n) printf(" ");
		if(nodes[temp].lc!=-1) q.push(nodes[temp].lc);
		if(nodes[temp].rc!=-1) q.push(nodes[temp].rc);
	}
}
int main(){
	scanf("%d",&n);
	char l,r;
	for(int i=0;i<n;i++){
		scanf("%*c%c %c",&l,&r);
		
		if(l>='0'&&l<='9'){
			nodes[i].lc=l-'0';
			inq[l-'0']=1;
		}else{
			nodes[i].lc=-1;
		}
		
		if(r>='0'&&r<='9'){
			nodes[i].rc=r-'0';
			inq[r-'0']=1;
		}else{
			nodes[i].rc=-1;
		}
	}
	int root;
	for(int i=0;i<n;i++) if(inq[i]==0) root=i;
	change(root);
	BFS(root);
	printf("\n");
	inorder(root);
	
}
```

# 树的遍历

## 1004**Counting Leaves**

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=110;
struct Node{
	vector<int> child;
};
Node node[maxn];
vector<int> v;
int maxD=0;
void DFS(int x,int depth){
	if(v.size()==depth){
		
		v.push_back(0);
	}
	if(node[x].child.size()==0){
//		cout<<maxD<<" "<<depth
		if(maxD<depth)maxD=depth;
		v[depth]++;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
//		cout<<"!";
		DFS(node[x].child[i],depth+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[ID].child.push_back(id);
			}
		}
	}
	v.push_back(0);
	DFS(1,1);
	for(int i=1;i<=maxD;i++){
		printf("%d",v[i]);
		if(i!=maxD) printf(" ");
	}
}
```

## 1053 **Path of Equal Weight**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int weight;
	vector<int> child;
}node[maxn];
int n,m,s;
void DFS(int x,int sum,vector<int> temp){
	sum+=node[x].weight;
	if(node[x].child.size()==0){
		if(sum==s){
			for(int i=0;i<temp.size();i++){
				printf("%d",node[temp[i]].weight);
				if(i!=temp.size()-1)printf(" ");
			}
			printf("\n");
		} 
		return;
	}
	if(sum>s) return;
	for(int i=0;i<node[x].child.size();i++){
		temp.push_back(node[x].child[i]);
		DFS(node[x].child[i],sum,temp);
		temp.pop_back();
	}
}
bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].weight);
	}
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[ID].child.push_back(id);
			}
			sort(node[ID].child.begin(),node[ID].child.end(),cmp);
		}
	}
	vector<int> ans;
	ans.push_back(0); 
	DFS(0,0,ans);
}
```

## 1064**Complete Binary Search Tree**

* BTS中序遍历就是从小到大顺序
* CBT另父节点下标x，子节点则为2\*x，2\*x+1

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n;
int num[maxn];
int CBT[maxn];
int cnt=0;
void inorder(int x){
	if(2*x<=n) inorder(2*x);
	CBT[x] = num[cnt++];
	if(2*x+1<=n)inorder(2*x+1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}	
	sort(num,num+n);
	inorder(1);
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i!=n)printf(" ");
	}
}
```



## **1079 Total Sales of Supply Chain**

```c++
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
double p,r;
struct Node{
	double product;
	vector<int> child;
};
Node node[maxn];
double sum=0;
void change(int x,double price){
	if(node[x].child.size()==0){
		sum+=node[x].product*price;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		int c = node[x].child[i];
		change(c,price*(1+r/100));
	}
}
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int k,id;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0){
			scanf("%lf",&node[i].product);
		}else{
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[i].child.push_back(id);
			}
		}
	}
	change(0,p);
	printf("%.1lf",sum);	
}
```

## 1090**Highest Price in Supply Chain**

```c++
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
double p,r;
struct Node{
	double data;
	vector<int> child;
};
Node node[maxn];
int maxDepth=0;
int cnt=0;
void DFS(int x,int depth){
	if(node[x].child.size()==0){
		if(depth>maxDepth){
			maxDepth=depth;
			cnt=1;
		}else if(depth==maxDepth){
			cnt++;
		}
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1); 
	}
}
double hprice(int x){
	double ans=p;
	for(int i=0;i<x;i++){
		ans*=(1+r/100);
	}
	return ans;
} 
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int root;
	for(int i=0;i<n;i++){
		int parent;
		scanf("%d",&parent);
		if(parent!=-1){
			node[parent].child.push_back(i);
		}else root = i;
	}
	DFS(root,0);
	printf("%.2lf %d",hprice(maxDepth),cnt);
}
```

## 1094**The Largest Generatio**

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=110;
struct Node{
	double data;
	vector<int> child;
};
Node node[maxn];
vector<int> v;

void DFS(int x,int depth){
	if(v.size()>depth){
		v[depth]++;
	}else{
		v.push_back(1);
	}
	if(node[x].child.size()==0){
		return;
	}
	
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int ID,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&id);
			node[ID].child.push_back(id);
		}
	}
	v.push_back(0);
	DFS(1,1);
	int idx=0;
	int Max=0;
	for(int i=1;i<v.size();i++){
		if(v[i]>Max){
			idx=i;
			Max=v[i];
		}
	}
	printf("%d %d",Max,idx);
}
```

## 1099 **Build A Binary Search Tree**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
struct Node{
	int data;
	int lc;
	int rc;
};
Node node[maxn];
int pre[maxn];
int cnt=0;
void inorder(int x){
	if(node[x].lc!=-1) inorder(node[x].lc);
	node[x].data = pre[cnt++];
	if(node[x].rc!=-1) inorder(node[x].rc);
}
int num=0;
void BFS(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		num++;
		printf("%d",node[temp].data);
		if(num!=n) printf(" ");
		if(node[temp].lc!=-1) q.push(node[temp].lc);
		if(node[temp].rc!=-1) q.push(node[temp].rc);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&node[i].lc,&node[i].rc);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}	
	sort(pre,pre+n);
	inorder(0);
	BFS(0);
}
```





## 1106 **Lowest Price in Supply Chain**

```c++
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
double p,r;
struct Node{
	double product;
	vector<int> child;
};
Node node[maxn];
vector<int> v;
int mindepth=maxn;
void DFS(int x,int depth){
	if(v.size()==depth){
//		cout<<x<<" ?";
		v.push_back(0);
	}
	if(node[x].child.size()==0){
		v[depth]++;
		if(depth<mindepth) mindepth = depth;
		return;
	}
	for(int i=0;i<node[x].child.size();i++){
		DFS(node[x].child[i],depth+1);
	}
}
double lprice(int x){
	double ans=p;
	for(int i=0;i<x;i++){
		ans*=(1+r/100);
	}
	return ans;
} 
int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int k,id;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&id);
				node[i].child.push_back(id);
			}
		}
	}
	v.push_back(0);
	DFS(0,1);
//	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//	cout<<endl;
	printf("%.4lf %d",lprice(mindepth-1),v[mindepth]);	
}
```

# AVL

## 1066

* *&一起

```c++
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,height;
	Node *lc;
	Node *rc;
}*root;
Node* newNode(int v){
	Node* n = new Node();
	n->data = v;
	n->height = 1;
	n->lc=n->rc=NULL;
	return n;
}
int getHeight(Node*root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node*root){
	root->height = max(getHeight(root->lc),getHeight(root->rc))+1;
}
int getBalanceFactor(Node* root){
	return (getHeight(root->lc)-getHeight(root->rc));
}
void L(Node*& root){
	Node *temp = root->rc;
	root->rc = temp->lc;
	temp->lc = root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;	
}
void R(Node*& root){
	Node* temp=root->lc;
	root->lc = temp->rc;
	temp->rc = root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(Node*&root,int v){
	if(root==NULL){
		root = newNode(v);
		return;
	} 
	if(v<root->data){
		insert(root->lc,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			
			if(getBalanceFactor(root->lc)==1){
//				cout<<root->data<<endl;
				R(root);
			}else if(getBalanceFactor(root->lc)==-1){
				L(root->lc);
				R(root);
			}
		} 
	}else{
		insert(root->rc,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rc)==1){
				R(root->rc);
				L(root);
			}else if(getBalanceFactor(root->rc)==-1){
				L(root);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d",root->data);
}
```

# 并查集

* 初始化！！！

## 1107 **Social Clusters** 

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int father[maxn]; 
int isRoot[maxn]={0};
int course[maxn]={0};

int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
	 	int z = a;
	 	a = father[a];
	 	father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA!=faB){
		father[faA] = faB;
	}
}

void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(course[h]==0){
				course[h]=i;
			}
			Union(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]) ans++;
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+1+n,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i!=ans) printf(" ");
	}
}

```

## 1013 

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=1111;
int n,m,k;
int cur;
vector<int> G[N];
int father[N];
int isRoot[N];
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
		int z=a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA!=faB){
		father[faA] = faB;
	}
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int cur;
	for(int q=0;q<k;q++){
		scanf("%d",&cur);
		init(n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<G[i].size();j++){
				int u=i,v=G[i][j];
				if(u==cur||v==cur) continue;
				Union(u,v);
			}
		}
		int block = 0;
		for(int i =1;i<=n;i++){
			if(i==cur) continue;
			int f = findFather(i);
			if(isRoot[f]==0) {
				isRoot[f]++;
				block++;
			}
			
		}
		printf("%d\n",block-1);
	}
}
```



# 图

* 有向边要区分清楚方向！！！

## 1013 **Battle Over Cities**

* 遍历有几个块

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=1111;
vector<int> G[N];
bool vis[N];
int n,m,k;
int cur;
void DFS(int v){
	if(v==cur){		
		return;
	}
	vis[v] = true;
	for(int i=0;i<G[v].size();i++){
		if(!vis[G[v][i]])
			DFS(G[v][i]);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&cur);
		memset(vis,false,sizeof(vis));
		int block=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&j!=cur){
				DFS(j);
				block++;
			}
		}
		printf("%d\n",block-1); 
	}	
}
```

## 1021 **Deepest Root**（优化方法很厉害）

* 并查集判断是不是树
* 随便找一个点找到最远的点，通过这个最远的点DFS获得的点集就是最深的根

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,root;
vector<int> G[N];


bool isRoot[N];
int father[N];
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[x]){
		int z=a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA!=faB){
		father[faA] = faB;
	}
}

int maxDepth=0;
vector<int> temp,ans;
void DFS(int x,int depth,int last){
	if(depth>maxDepth){
		maxDepth = depth;
		temp.clear();
		temp.push_back(x);
	}
	if(depth==maxDepth){
		temp.push_back(x);	
	}
	for(int i=0;i<G[x].size();i++){
		if(G[x][i]!=last){
			DFS(G[x][i],depth+1,x);

		}		
	}
}
void init(){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	
	int block=0;
	for(int i=1;i<=n;i++){
		int f = findFather(i);
//		cout<<f<<endl;
		if(!isRoot[f]){
			block++;
			isRoot[f] = true;
		}
	}
	if(block!=1){
		printf("Error: %d components",block);
		return 0;
	}

	DFS(1,0,1);
	ans = temp;
	DFS(ans[0],0,ans[0]);
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans[0]);
	for(int i=1;i<ans.size();i++){
		if(ans[i]!=ans[i-1])
			printf("%d\n",ans[i]);
	}
	
}
```



## 1034 **Head of a Gang** 

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,k;
map<string,int> sTi;
map<int,string> iTs;
map<string,int> Gang;
int G[N][N]={0},weight[N]={0};
bool vis[N]={false};
int numPerson=0;
int change(string name){
	if(sTi.find(name)==sTi.end()){
		sTi[name] = numPerson;
		iTs[numPerson] = name;
//		cout<<name<<" "<<numPerson<<endl;
		return numPerson++; 
	}else{
		return sTi[name];
	}
}
void DFS(int x,int& total,int& head,int& num){
	num++;
	vis[x] = true;
	if(weight[head]<weight[x]){
		head = x;
	}
	for(int i=0;i<numPerson;i++){
		if(G[x][i]>0){
//			cout<<x<<" "<<i<<" "<<G[x][i]<<endl; 
			total += G[x][i];
			G[x][i] = G[i][x] = 0;
			if(!vis[i])
				DFS(i,total,head,num);
		}
	} 
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		string a,b;
		int t;
		cin>>a>>b>>t;
		int id1 = change(a);
		int id2 = change(b);
//		cout<<a<<":"<<id1<<" "<<b<<":"<<id2<<endl;
		G[id1][id2] += t; 
		G[id2][id1] += t;
		weight[id1] += t;
		weight[id2] += t;
	}
	for(int i=0;i<numPerson;i++){		
		if(!vis[i]){
			int total=0,head=i,num=0;
			DFS(i,total,head,num);
			if(num>2&&total>k){
				Gang[iTs[head]] = num;
			}
		}
	}
	cout<<Gang.size()<<endl;
	for(map<string,int>::iterator it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
```

## 1076 Forwards on Weibo

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool vis[maxn]={false};
int n,l,k;

void BFS(int x,int &depth,int& num){
	queue<int> q;
	queue<int> temp;
	q.push(x);
	while(!q.empty()){
		int t = q.front();
		q.pop();	
		vis[t] = true;
		for(int i=0;i<G[t].size();i++){
			if(!vis[G[t][i]]){
				vis[G[t][i]] = true;
//				cout<<"?"<<G[t][i]<<endl;
				temp.push(G[t][i]);
				num++;
			}
		
		}
		if(q.empty()) {
//			cout<<depth<<endl;
			q=temp;
			while(!temp.empty()) temp.pop();
			depth++;
			if(depth==l) return;
		}
	}
}
int init(){
	for(int i=1;i<=n;i++)
		vis[i] = false;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		int M,id;
		scanf("%d",&M);
		for(int j=0;j<M;j++){
			scanf("%d",&id);
			G[id].push_back(i);
		}
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		int id;
		scanf("%d",&id);
		int cnt=0,depth=0;
		init();
		BFS(id,depth,cnt);
		printf("%d\n",cnt);	
	}
}
```

## 1030**Travel Plan**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
int G[maxn][maxn],C[maxn][maxn];
int vis[maxn];
int n,m,s,d;
int mind=0; 
int finalcost=0x7fffffff,finaldistance=0x7fffffff;
vector<int> temp,ans;
void DFS(int cur,int distance,int cost,vector<int> v){
	if(distance>finaldistance||cost>finalcost) return;
	if(cur==d){
//		cout<<"?";
		if(distance<finaldistance){
			finaldistance = distance;
			finalcost = cost;
			ans = v;
		}else if(distance == finaldistance){
			if(cost<finalcost){
				finalcost = cost;
				ans = v;
			}
		}
		return;
	}

	for(int i=0;i<n;i++){
//		cout<<cur<<" "<<i<<" "<<G[cur][i]<<" "<<vis[i]<<" "<<distance+G[cur][i]<<endl;
		if(G[cur][i]>0&&vis[i]>distance+G[cur][i]){ 
			v.push_back(i);
			int t = vis[cur];
			vis[cur] = distance;
			DFS(i,distance+G[cur][i],cost+C[cur][i],v);
			vis[cur] = t;
			v.pop_back();
		}
	}
}
int main(){
	 scanf("%d%d%d%d",&n,&m,&s,&d);
	 for(int i=0;i<m;i++){
	 	int a,b,x,y;
	 	scanf("%d%d%d%d",&a,&b,&x,&y);
	 	G[a][b] = G[b][a] = x;
	 	C[a][b] = C[b][a] = y;
	 	vis[i] = 0x7fffffff;
	 }
	 temp.push_back(s);
	 DFS(s,0,0,temp);
	 for(int i=0;i<ans.size();i++){
	 	printf("%d ",ans[i]);
	 }
	 printf("%d %d",finaldistance,finalcost);
	 
}
```

## 1087 **All Roads Lead to Rom**

* vis[i] == vis[s]+G\[s][i]也应访问i节点

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 222;
const int INF = 0x7fffffff;
int n,k;
map<string,int> sti;
map<int,string> its;
int G[maxn][maxn],d[maxn];
int vis[maxn];
int h[maxn];
int cnt=0;
int getID(string str){
	if(sti.find(str)==sti.end()){
		sti[str] = cnt;
		its[cnt] = str;
		cnt++;
	}
	return sti[str];
}
//void Dijkstra(int s){
//	memset(vis,false,sizeof(vis));
//	fill(d,d+maxn,INF);
//	
//}
int minCost=INF,minDis=INF,maxH=0,avgH=0;
vector<int>temp,ans;
void DFS(int s,int dis,int totalH,int totalC,vector<int> v){
	if(s==getID("ROM")){
		if(dis<minDis){
			minDis=dis;
			cnt=1;
			maxH=totalH;
			avgH=totalH/(v.size()-1);
			ans = v;
		}else if(dis==minDis){
			cnt++;
			if(totalH>maxH){
				maxH=totalH;
				avgH=totalH/(v.size()-1);
				ans = v;
			}else if(totalH==maxH&&totalH/(v.size()-1)>avgH){
				avgH=totalH/(v.size()-1);
				ans = v;
			}
		}
		return;
	}
	vis[s] = dis;
	for(int i=0;i<n;i++){
		if(G[s][i]>0&&vis[s]+G[s][i]<=vis[i]){
			v.push_back(i);
			DFS(i,vis[s]+G[s][i],totalH+h[i],totalC,v);
			v.pop_back();
		}
	}
}
int main(){
	string start,city1,city2;
	int t;
	cin>>n>>k>>start;
	getID(start);
	for(int i=1;i<n;i++){
		cin>>city1>>t;
		getID(city1);
		h[i] = t;
	}
	
	for(int i=0;i<k;i++){
		cin>>city1>>city2>>t;
		int id1 = getID(city1);
		int id2 = getID(city2);
		G[id1][id2] = G[id2][id1] = t;
	}		
	fill(vis,vis+maxn,INF);
	temp.push_back(0);
	DFS(0,0,0,0,temp);
	printf("%d %d %d %d\n",cnt,minDis,maxH,avgH);
	cout<<its[0];
	for(int i=1;i<ans.size();i++){
		cout<<"->"<<its[ans[i]];
	}
	
}
```



# Dijkstra

## 1072**Gas Station**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1015;
int n,m,k,D;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
const int INF = 0x7fffffff; 
int getID(char city[]){
	int idx = 0;
	int id=0;
	int c=0;
	if(city[idx]=='G'){
		idx++;
		c=n;
	}	
	int len = strlen(city) ;
	for(idx;idx<len;idx++){
		id = id*10+city[idx]-'0';
	}
	return id+c;
}
void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n+m;j++){
			if(!vis[j]&&d[j]<MIN){
				u=j;
				MIN = d[j];
			}
		} 
		if(u==-1) return;
		vis[u] = true;
		for(int v=1;v<=n+m;v++){
			if(!vis[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u]+G[u][v];
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&D);
	int w;
	
	char city1[5],city2[5];
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",&city1,&city2,&w);
		int id1 = getID(city1);
		int id2 = getID(city2);
		G[id1][id2] = G[id2][id1] = w;
	}
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<=m+n;i++){
//		init();
		double minDis=INF,avg=0;
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>D){
				minDis = -1;
				break;
			}
			if(d[j]<minDis) minDis = d[j];
			avg+= 1.0*d[j]/n;
		} 
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}else if(minDis==ansDis&&avg<ansAvg){
			ansID = i;
			ansAvg=avg;
		}
	}
	if(ansID==-1) printf("No Solution\n");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
} 
```

# 动态规划

## 1045 **Favorite Color Stripe**

* 最长不下降子序列

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=222;
const int N=10010
int n,m;
int col[N];
int H[maxn];
int dp[N];
//map<int,int> mp;
int main(){
	scanf("%d%d",&n,&m);
	int x;
	memset(H,-1,sizeof(H));
//	memset(col,-1,sizeof(col));
//	memset(dp,1,sizeof(dp));
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		H[x] = i;
	}
	int k,num=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){		
		scanf("%d",&x);
		if(H[x]>=0){
			col[num++] = H[x];
		}
	}
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(col[j]<=col[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
```

* 最长公共子序列

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=222;
const int N=10010;
int n,m,k;
int A[maxn],B[N],dp[maxn][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);
		dp[i][0] = 0;
	}
	scanf("%d",&k);
	for(int j=1;j<=k;j++){
		scanf("%d",&B[j]);
		dp[0][j] = 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(A[i]==B[j]){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1])+1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[m][k]);
}
```

## 1040**Longest Symmetric String**

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string s;
int dp[maxn][maxn];
int main(){
	getline(cin,s);
	int len = s.size(),ans=1;
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int i=3;i<=len;i++){
// 		cout<<i<<endl;
		for(int j=0;j+i-1<len;j++){
			if(s[j]==s[j+i-1]&&dp[j+1][j+i-1-1]==1){
				dp[j][j+i-1]=1;
				ans = i;
			}
		}
	}
	printf("%d\n",ans);
}
```

