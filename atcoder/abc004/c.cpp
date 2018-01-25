#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(6);
	for (int i = 0; i < v.size(); i++) {
		v[i] = (i + n / (v.size() - 1)) % 6 + 1;
	}
	for (int i = 0; i < n % (v.size() - 1); i++) {
		int t = v[i];
		v[i] = v[i + 1];
		v[i + 1] = t;
	}
	for (auto e : v) {
		cout << e;
	}
	cout << endl;
	return 0;
}
