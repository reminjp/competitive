#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	bool e = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		e &= a[i] == b[i];
	}
	if (e) {
		cout << 0 << endl;
	} else {
		ll s = 0;
		int m = INT_MAX;
		for (int i = 0; i < n; i++) {
			s += a[i];
			if (a[i] > b[i]) {
				m = min(m, b[i]);
			}
		}
		cout << s - m << endl;
	}
	return 0;
}
