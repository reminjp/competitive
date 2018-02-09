#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	vector<vector<int>> b(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		b[0][i] = a[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = min(b[i - 1][j], a[(n + j - i) % n]);
		}
	}
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		s[i] = (ll)i * x;
		for (int j = 0; j < n; j++) {
			s[i] += b[i][j];
		}
	}
	ll m = s.front();
	for (auto e : s) {
		if (e < m) {
			m = e;
		}
	}
	cout << m << endl;
	return 0;
}
