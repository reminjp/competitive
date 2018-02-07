#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int k;
	cin >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	if (a[k - 1] == 2) {
		ll m = 2, n = 2 * 2 - 1;
		for (int i = k - 2; i >= 0 && m <= n; i--) {
			m = ((m - 1) / a[i] + 1) * a[i];
			n = (n / a[i] + 1) * a[i] - 1;
		}
		if (m <= n) {
			cout << m << " " << n << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
