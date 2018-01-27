#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> v(4);
	for (auto c : s) {
		v[c - '1']++;
	}
	int a = n, b = 0;
	for (auto e : v) {
		a = min(a, e);
		b = max(b, e);
	}
	cout << b << " " << a << endl;
	return 0;
}
