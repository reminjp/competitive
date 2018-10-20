#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c, k;
	cin >> n >> c >> k;
	vector<int> t(n);
	for (auto &e : t) {
		cin >> e;
	}
	sort(begin(t), end(t));
	int m = 0, a = 0, b = 0;
	for (auto e : t) {
		if (m == 0 || c <= a || b + k < e) {
			m++;
			a = 1;
			b = e;
		} else {
			a++;
		}
	}
	cout << m << endl;
	return 0;
}
