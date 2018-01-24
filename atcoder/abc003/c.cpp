#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	sort(begin(r), end(r));
	float c = 0;
	for (int i = n - k; i < n; i++) {
		c = (c + r[i]) / 2.0;
	}
	cout << fixed << setprecision(6) << c << endl;
	return 0;
}
