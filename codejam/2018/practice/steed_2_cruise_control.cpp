#include <bits/stdc++.h>
using namespace std;

void solve() {
	int d, n;
	cin >> d >> n;
	double t = 0;
	for (int i = 0; i < n; i++) {
		int k, s;
		cin >> k >> s;
		t = max(t, double(d - k) / s);
	}
	cout << fixed << setprecision(6) << d / t << endl;
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
