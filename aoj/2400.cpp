// 2016-12-10
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t, p, r, ti, pi, tt;
	int c[50], w[50][10], a[50];
	string m;
	while (cin >> t >> p >> r, t) {
		for (int i = 0; i < t; i++) {
			c[i] = 0;
			a[i] = 0;
			for (int j = 0; j < p; j++) {
				w[i][j] = 0;
			}
		}
		for (int i = 0; i < r; i++) {
			cin >> ti >> pi >> tt >> m;
			if (m[0] == 'C') {
				c[ti - 1]++;
				a[ti - 1] += w[ti - 1][pi - 1] * 1200 + tt;
			} else {
				w[ti - 1][pi - 1]++;
			}
		}
		vector<pair<pair<int, int>, int>> v;
		for (int i = 0; i < t; i++) {
			v.push_back(make_pair(make_pair(p - c[i], a[i]), i));
		}
		sort(begin(v), end(v));
		for (int i = 0; i < t; i++) {
			cout << v[i].second + 1 << ' ' << p - v[i].first.first << ' ' << v[i].first.second << endl;
		}
	}
	return 0;
}
