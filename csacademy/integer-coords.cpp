#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	set<pair<int, int>> v;
	if (k <= n + 1) {
		v.insert(make_pair(k - 1, 0));
	}
	if (k <= m + 1) {
		v.insert(make_pair(0, k - 1));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (gcd(i, j) + 1 == k) {
				v.insert(make_pair(i, j));
			}
		}
	}
	int r = 0;
	for (auto e : v) {
		r += ((e.first && e.second) + 1) * (n - e.first + 1) * (m - e.second + 1);
	}
	cout << r << endl;
	return 0;
}
