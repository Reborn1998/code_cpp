#include<iostream>
#include<vector>
using namespace std;
int* sort(int *arr,int num){
	int *b = new int[num];
	for(int i=0;i<num;i++) b[i] = arr[i];
	int temp;
	for(int j=1;j<num;j++){	
		for(int i=0;i<num-j;i++){
			if(b[i]>b[i+1]){				
				temp = b[i];
				b[i] = b[i+1];
				b[i+1] = temp;
			}
		}
	}
	return b;
}
vector<int> sort(vector<int> &v){
	vector<int> vv(v);
	int temp;
	for(int j=1;j<vv.size();j++){	
		for(int i=0;i<vv.size()-j;i++){
			if(vv[i]>vv[i+1]){						
				temp = vv[i];
				vv[i] = vv[i+1];
				vv[i+1] = temp;			
			}
		}
	}
	return vv;
}
int main(){
	int a[10] = {1,6,1,51,25,12,54,211,52,4};
	int *b;
	b = sort(a,10);
	for(int i=0;i<10;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=0;i<10;i++) cout<<b[i]<<" ";
	delete[] b;
	cout<<"\n";
	vector<int> v;
	v.push_back(1);
	v.push_back(6);
	v.push_back(1);
	v.push_back(51);
	v.push_back(25);
	v.push_back(112);
	v.push_back(54);
	v.push_back(211);
	v.push_back(52);
	v.push_back(4);
	v.push_back(3);	
	vector<int> vv = sort(v);
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<"\n";
	for(int i=0;i<v.size();i++) cout<<vv[i]<<" ";
} 
