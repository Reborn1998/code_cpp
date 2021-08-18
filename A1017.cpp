#include<bits/stdc++.h>
using namespace std;
int n,k;
struct Customer{
	int comeTime,serveTime;
}c;
vector<Customer> v;
int endTime[111];
int convertTime(int  h,int m,int s){
	return 3600*h+m*60+s;
}
bool cmp(Customer a,Customer b){
	return a.comeTime<b.comeTime;
}
int main(){
	int total=0;
	scanf("%d%d",&n,&k);
	int startTime = convertTime(8,0,0);
	int edTime = convertTime(17,0,0);
	for(int i=0;i<n;i++){
		int h,m,s;
		int t;
		scanf("%d:%d:%d %d",&h,&m,&s,&t);
		c.comeTime = convertTime(h,m,s);
		if(c.comeTime>edTime) continue; 
		c.serveTime = t<=60?t*60:3600;
		v.push_back(c);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<k;i++) endTime[i] = startTime; 
	for(int i=0;i<v.size();i++){
		int idx=0,minEnd = 0x7fffffff;
		for(int j=0;j<k;j++){
			if(endTime[j]<minEnd){
				minEnd = endTime[j];
				idx = j;
			}
		}
		if(endTime[idx]<=v[i].comeTime){
			
			endTime[idx] = v[i].comeTime + v[i].serveTime; 
		}else{
			total =total + endTime[idx] - v[i].comeTime; 
			endTime[idx] += v[i].serveTime;
		}
	}
	if(v.size()==0) printf("0.0");
	else printf("%.1f",total/60.0/v.size());
}
