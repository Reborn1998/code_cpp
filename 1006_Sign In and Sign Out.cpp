/*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct person {
	string name;
	string in;
	string out;
};
bool com(person& p1, person& p2) {
	int H, M, S;
	H = 10 * (p1.in[0] - '0') + p1.in[1] - '0';
	M = 10 * (p1.in[3] - '0') + p1.in[4] - '0';
	S = 10 * (p1.in[6] - '0') + p1.in[7] - '0';
	int HH, MM, SS;
	HH = 10 * (p2.in[0] - '0') + p2.in[1] - '0';
	MM = 10 * (p2.in[3] - '0') + p2.in[4] - '0';
	SS = 10 * (p2.in[6] - '0') + p2.in[7] - '0';
	if (H == HH) {
		if (M == MM) {
			return S < SS;
		}
		return M < MM;
	}
	return H < HH;
}
bool com1(person& p1, person& p2) {
	int H, M, S;
	H = 10*(p1.out[0]-'0') + p1.out[1]-'0';
	M = 10 * (p1.out[3] - '0') + p1.out[4] - '0';
	S = 10 * (p1.out[6] - '0') + p1.out[7] - '0';
	int HH, MM, SS;
	HH = 10 * (p2.out[0] - '0') + p2.out[1] - '0';
	MM = 10 * (p2.out[3] - '0') + p2.out[4] - '0';
	SS = 10 * (p2.out[6] - '0') + p2.out[7] - '0';
	if (H == HH) {
		if (M == MM) {
			return S > SS;
		}
		return M > MM;
	}
	return H > HH;
}
vector<person> v;
int main() {
	int N;
	cin >> N;
	while (N--) {
		person p;
		cin >> p.name >> p.in >> p.out;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), com);
	cout << v[0].name<<" ";
	sort(v.begin(), v.end(), com1);
	cout << v[0].name;
}*/

#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	cin>>N;
	string earlist_in = "999",latest_out="000";
	string earlist,latest;
	while(N--){
		string a,b,c;
		cin>>a>>b>>c;
		if(b<earlist_in){
			earlist_in = b;
			earlist = a;
		}
		if(c>latest_out){
			latest_out = c;
			latest = a;
		}
		cout<<earlist<<" "<<latest;
	}	
}
