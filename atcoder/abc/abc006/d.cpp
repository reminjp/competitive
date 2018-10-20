#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (auto &e : c) {
		cin >> e;
	}
	vector<int> r(n), v(n, n + 1);
	for (int i = 0; i < n; i++) {
		int b = 0, t = n, m;
		while (b < t) {
			m = (b + t) / 2;
			if (v[m] <= c[i]) {
				b = m + 1;
			} else {
				t = m;
			}
		}
		r[i] = b + 1;
		v[b] = min(v[b], c[i]);
	}
	int k = 0;
	for (auto e : r) {
		k = max(k, e);
	}
	cout << n - k << endl;
	return 0;
}
