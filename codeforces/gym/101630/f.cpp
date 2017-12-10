#include <bits/stdc++.h>
using namespace std;

int main() {
	int M;
	cin >> M;
	for (int m = 0; m < M; m++) {
		int a, b, n;
		cin >> a >> b >> n;
		int sign_a = 1, sign_b = 1;
		if (a < 0) {
			a *= -1;
			sign_a = -1;
		}
		if (b < 0) {
			b *= -1;
			sign_b = -1;
		}
		bool reversed = a < b;
		if (reversed) {
			int t = a;
			a = b;
			b = t;
		}
		vector<pair<pair<int, int>, pair<int, int>>> v;
		while (a >= 0 || b >= 0) {
			if (a < n && b < n) {
				if (v.empty() || a < v.back().first.first) {
					v.push_back(make_pair(make_pair(a, n - 1), make_pair(a - n + 1, 0)));
				} else {
					v.push_back(make_pair(make_pair(0, b - n + 1), make_pair(n - 1, b)));
				}
				a = -1;
				b = -1;
			} else {
				v.push_back(make_pair(make_pair(a - n + 1, b - n + 1), make_pair(a, b)));
				if (b < n) {
					a -= n;
					b = 0;
				} else if (a < b) {
					a -= n - 1;
					b -= n;
				} else {
					a -= n;
					b -= n - 1;
				}
			}
		}
		cout << v.size() << endl;
		if (reversed) {
			for (auto e : v) {
				cout << sign_a * e.second.second << " " << sign_b * e.second.first << " ";
				cout << sign_a * e.first.second << " " << sign_b * e.first.first << endl;
			}
		} else {
			for (auto e : v) {
				cout << sign_a * e.first.first << " " << sign_b * e.first.second << " ";
				cout << sign_a * e.second.first << " " << sign_b * e.second.second << endl;
			}
		}
	}
	return 0;
}
