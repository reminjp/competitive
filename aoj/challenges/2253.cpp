// 2017-01-05
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define MAX 30

int dx[6] = {1, 1, 0, -1, -1, 0};
int dy[6] = {0, 1, 1, 0, -1, -1};

int main() {
	int t, n, x, y;
	bool m[MAX * 4 + 1][MAX * 4 + 1];
	queue<pair<int, pair<int, int>>> q;
	while (cin >> t >> n, t) {
		fill(m[0], m[MAX * 4 + 1], false);
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			x += MAX * 2; y += MAX * 2;
			m[y][x] = true;
		}
		cin >> x >> y;
		x += MAX * 2; y += MAX * 2;
		int c = 1;
		m[y][x] = true;
		q.push(make_pair(t, make_pair(x, y)));
		while (!q.empty()) {
			auto e = q.front();
			q.pop();
			t = e.first; x = e.second.first; y = e.second.second;
			if (t > 0) {
				for (int i = 0; i < 6; i++) {
					if (!m[y + dy[i]][x + dx[i]]) {
						c++;
						m[y + dy[i]][x + dx[i]] = true;
						q.push(make_pair(t - 1, make_pair(x + dx[i], y + dy[i])));
					}
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}
