#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, k;
	cin >> n >> k;
	map<ll, ll> m;
	m[n] = 1;
	for (ll i = 1; i < k; k -= i, i *= 2) {
		map<ll, ll> t;
		for (auto e : m) {
			t[(e.first - 1) / 2] += e.second;
			t[e.first / 2] += e.second;
		}
		m = t;
	}
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		if (it->second < k) {
			k -= it->second;
		} else {
			cout << it->first / 2 << " " << (it->first - 1) / 2 << endl;
			break;
		}
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
