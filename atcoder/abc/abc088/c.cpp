#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 3;
	vector<vector<int>> c(n, vector<int>(n));
	for (auto& r : c) {
		for (auto& e : r) {
			cin >> e;
		}
	}
	for (int i = 0; i < n; i++) {
		int m = INT_MAX;
		for (int j = 0; j < n; j++) {
			m = min(m, c[i][j]);
		}
		for (int j = 0; j < n; j++) {
			c[i][j] -= m;
		}
	}
	bool r = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r &= c[i][j] == c[0][j];
		}
	}
	cout << (r ? "Yes" : "No") << endl;
	return 0;
}
