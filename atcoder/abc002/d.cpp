#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = 1 << i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x] |= 1 << y;
		v[y] |= 1 << x;
	}
	int r = 0;
	for (int i = 0; i < 1 << n; i++) {
		int t = (1 << n) - 1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				t &= v[j];
			}
		}
		if ((t & i) == i) {
			int c = 0;
			for (int j = 0; j < n; j++) {
				c += (i & 1 << j) != 0;
			}
			r = max(r, c);
		}
	}
	cout << r << endl;
	return 0;
}
