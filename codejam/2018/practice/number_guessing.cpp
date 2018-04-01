#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, n;
	cin >> a >> b >> n;
	a++;
	b++;
	int m;
	for (int i = 0; i < n; i++) {
		m = (a + b) / 2;
		cout << m << endl;
		string s;
		cin >> s;
		if (s == "TOO_SMALL") {
			a = m + 1;
		} else if (s == "TOO_BIG") {
			b = m;
		} else {
			break;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}
