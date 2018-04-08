#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a;
	cin >> a;
	int h, w;
	h = max(3, (int)sqrt(a));
	w = max(3, (a - 1) / h + 1);
	vector<vector<bool>> m(h, vector<bool>(w));
	while (true) {
		int y = 1, x = 1, s = 9;
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++) {
				int t = 0;
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						t += m[k][l];
					}
				}
				if (t < s) {
					y = i;
					x = j;
					s = t;
				}
			}
		}
		cout << y + 1 << " " << x + 1 << endl;
		cin >> y >> x;
		if (y > 0 && x > 0) {
			m[y - 1][x - 1] = true;
		} else {
			break;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (; t > 0; t--) solve();
	return 0;
}
