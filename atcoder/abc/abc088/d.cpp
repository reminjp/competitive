#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (auto &e : s) {
		cin >> e;
	}
	vector<pair<int, int>> d = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
	vector<vector<int>> a(h, vector<int>(w, INT_MAX));
	queue<pair<int, int>> q;
	a[0][0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (auto e : d) {
			int i = f.first + e.first, j = f.second + e.second;
			if (0 <= i && i < h && 0 <= j && j < w && s[i][j] == '.') {
				if (a[f.first][f.second] + 1 < a[i][j]) {
					a[i][j] = a[f.first][f.second] + 1;
					q.push(make_pair(i, j));
				}
			}
		}
	}
	int m;
	if (a[h - 1][w - 1] == INT_MAX) {
		m = -1;
	} else {
		int t = 0;
		for (auto r : s) {
			for (auto e : r) {
				t += e == '.';
			}
		}
		m = t - a[h - 1][w - 1] - 1;
	}
	cout << m << endl;
	return 0;
}
