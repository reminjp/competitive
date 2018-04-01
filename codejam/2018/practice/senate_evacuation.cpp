#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int s = 0;
	vector<pair<int, char>> v;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		s += p;
		v.push_back(make_pair(p, char('A' + i)));
	}
	vector<string> r;
	while (s) {
		sort(v.rbegin(), v.rend());
		while (v.back().first == 0) {
			v.pop_back();
		}
		if (s == 3) {
			r.push_back(string{v[0].second});
			s--;
			v[0].first--;
		} else if (v[1].first + 2 <= v[0].first) {
			r.push_back(string{v[0].second, v[0].second});
			s -= 2;
			v[0].first -= 2;
		} else {
			r.push_back(string{v[0].second, v[1].second});
			s -= 2;
			v[0].first--;
			v[1].first--;
		}
	}
	for (auto e : r) {
		cout << e << " ";
	}
	cout << endl;
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
