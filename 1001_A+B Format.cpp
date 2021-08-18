#include<iostream>
#include<string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	string str = to_string(sum);
	if (str[0] == '-') {
		int cnt = 0;
		for (int i = str.size()-1; i>1; i--) {
			cnt++;
			if (cnt == 3) {
				str.insert(str.begin() + i, ',');
				cnt = 0;
			}
		}
	}
	else {
		int cnt = 0;
		for (int i = str.size() - 1; i > 0; i--) {
			cnt++;
			if (cnt == 3) {
				str.insert(str.begin() + i, ',');
				cnt = 0;
			}
		}
	}
	cout << str << endl;
}