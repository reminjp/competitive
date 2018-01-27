#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, sy, sx, gy, gx;
	cin >> h >> w >> sy >> sx >> gy >> gx;
	sy--;
	sx--;
	gy--;
	gx--;
	vector<string> c(h);
	for (auto& s : c) {
		cin >> s;
	}
	vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<vector<int>> r(h, vector<int>(w, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	r[sy][sx] = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto e : d) {
			if (c[p.first + e[0]][p.second + e[1]] == '.' && r[p.first + e[0]][p.second + e[1]] == -1) {
				r[p.first + e[0]][p.second + e[1]] = r[p.first][p.second] + 1;
				q.push(make_pair(p.first + e[0], p.second + e[1]));
			}
		}
	}
	cout << r[gy][gx] << endl;
	return 0;
}
