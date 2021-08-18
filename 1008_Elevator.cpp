#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main(){
	int N;
	cin>>N;
	int temp;
	v.push_back(0);
	for(int i=0;i<N;i++){
		cin>>temp;
		v.push_back(temp);
	}
	int sum=0;
	for(int i=1;i<v.size();i++){
		if(v[i]-v[i-1]>0){
			sum += (v[i]-v[i-1])*6+5;
		}
		else{
			sum += (v[i-1]+v[i])*4+5;
		}
		cout<<sum<<endl;
	}
	cout<<sum;
} 
