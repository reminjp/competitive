#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		a[i] %= b[i];
	}
	int64_t m = 0;
	for (int i = n - 1; i >= 0; i--) {
		if ((a[i] + m) % b[i] != 0) {
			m += b[i] - (a[i] + m) % b[i];
		}
	}
	cout << m << endl;
	return 0;
}
