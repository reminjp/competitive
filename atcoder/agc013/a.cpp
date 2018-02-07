#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	vector<int> d(n - 1);
	for (int i = 0; i < n - 1; i++) {
		d[i] = a[i + 1] - a[i];
	}
	int m = 1;
	for (int i = 0; i < n - 2; i++) {
		if (d[i + 1] == 0) {
			d[i + 1] = d[i];
		} else if (d[i] < 0 && 0 < d[i + 1] || d[i + 1] < 0 && 0 < d[i]) {
			m++;
			i++;
		}
	}
	cout << m << endl;
	return 0;
}
