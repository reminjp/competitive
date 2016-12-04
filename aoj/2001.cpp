// 2016-12-05
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct line { int h, p, q; };

int main() {
	int n, m, a, h, p, q;
	int r[100];
	vector<line> v;
	while (cin >> n >> m >> a, n) {
		v.clear();
		for (int i = 0; i < m; i++) {
			cin >> h >> p >> q;
			line l = {h, p - 1, q - 1};
			v.push_back(l);
		}
		sort(begin(v), end(v), [](const line& x, const line& y) { return x.h < y.h; });
		for (int i = 0; i < n; i++) {
			r[i] = i;
		}
		for (auto l : v) {
			swap(r[l.p], r[l.q]);
		}
		cout << r[a - 1] + 1 << endl;
	}
	return 0;
}
