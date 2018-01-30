#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.back() == '.') {
			s.pop_back();
		}
		m += s == "TAKAHASHIKUN" || s == "Takahashikun" || s == "takahashikun";
	}
	cout << m << endl;
	return 0;
}
