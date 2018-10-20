#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(3 * n);
	for (auto &e : a) {
		cin >> e;
	}
	sort(begin(a), end(a));
	long long m = 0;
	for (int i = 0; i < n; i++) {
		m += a[n + 2 * i];
	}
	cout << m << endl;
	return 0;
}
