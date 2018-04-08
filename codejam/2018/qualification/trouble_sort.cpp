#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> u(2, vector<int>((n + 1) / 2, INT_MAX));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		u[i % 2][i / 2] = a;
	}
	for (auto& e : u) {
		sort(begin(e), end(e));
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(u[i % 2][i / 2]);
	}
	int r;
	for (r = 0; r < n - 1; r++) {
		if (v[r] > v[r + 1]) {
			break;
		}
	}
	if (r < n - 1) {
		cout << r << endl;
	} else {
		cout << "OK" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
