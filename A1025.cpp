#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu{
	string id;
	int grade;
	int location_number;
	int local_rank;
}stu[30010];
bool cmp(Stu a,Stu b){
	return (a.grade!=b.grade)?a.grade>b.grade:a.id<b.id;
}
int main(){
	int N;
	int idx = 0;
	cin>>N;
	for(int i=1;i<=N;i++){
		int n;
		cin>>n;
		string temp;
		int g;
		for(int j=0;j<n;j++){
			cin>>temp>>g;
			stu[idx].id = temp;
			stu[idx].grade = g; 
			stu[idx++].location_number = i;
		}	
		sort(stu+idx-n,stu+idx,cmp);
		int rank=1;
		for(int j=idx-n;j<idx;j++){
			if(j!=idx-n && stu[j].grade!=stu[j-1].grade){
				rank = j-idx+n+1;
				stu[j].local_rank = rank; 
			}else{
				stu[j].local_rank = rank;
			}
			
		}
		
	}
	cout<<idx<<endl;
	sort(stu,stu+idx,cmp);
	int r  = 1;
	for(int i=0;i<idx;i++){
		
		if(i!=0 && stu[i-1].grade!=stu[i].grade){
			r = i+1;
		}
		cout<<stu[i].id<<" "<<r<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<"\n";
	}
}
