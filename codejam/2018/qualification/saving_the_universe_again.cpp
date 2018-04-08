#include <bits/stdc++.h>
using namespace std;

void solve() {
	int d;
	string p;
	cin >> d >> p;
	vector<int> m(30);
	int c = 0;
	for (auto e : p) {
		if (e == 'C') {
			c++;
		} else {
			m[c]++;
		}
	}
	int s = 0;
	for (int i = 0; i < m.size(); i++) {
		s += m[i] * (1 << i);
	}
	int r = 0;
	for (int i = m.size() - 1; i >= 1 && d < s;) {
		if (m[i]) {
			r++;
			s = s - (1 << i) + (1 << i - 1);
			m[i]--;
			m[i - 1]++;
		} else {
			i--;
		}
	}
	if (s <= d) {
		cout << r << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
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
