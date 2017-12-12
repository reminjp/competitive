#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, w;
	while (cin >> n >> w, n) {
		vector<int> v(n);
		int m = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m = max(m, v[i]);
		}
		vector<int> u(m / w + 1);
		for (auto i : v) {
			u[i / w]++;
		}
		int h = 0;
		for (auto i : u) {
			h = max(h, i);
		}
		double r = 0.01;
		for (int i = 0; i < u.size(); i++) {
			r += double(u.size() - 1 - i) / (u.size() - 1) * u[i] / h;
		}
		cout << fixed << setprecision(6) << r << endl;
	}
	return 0;
}
