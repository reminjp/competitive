#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, d;
	cin >> h >> w >> d;
	vector<pair<int, int>> p(h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			p[a - 1] = make_pair(i, j);
		}
	}
	vector<int> m(h * w);
	for (int i = d; i < h * w; i++) {
		m[i] = m[i - d] + abs(p[i].first - p[i - d].first) + abs(p[i].second - p[i - d].second);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << m[r - 1] - m[l - 1] << endl;
	}
	return 0;
}
