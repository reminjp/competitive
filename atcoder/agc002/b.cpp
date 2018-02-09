#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> k(n, 1);
	vector<bool> r(n, false);
	r[0] = true;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		k[x]--;
		k[y]++;
		r[y] = r[y] || r[x];
		r[x] = r[x] && k[x] != 0;
	}
	int c = 0;
	for (auto e : r) {
		c += e;
	}
	cout << c << endl;
	return 0;
}
