// 2017-02-21
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m, n) {
		vector<pair<int, pair<int, int>>> v;
		for (int i = 0; i < m; i++) {
			int t, s, d;
			cin >> t >> s >> d;
			v.push_back(make_pair(t, make_pair(s - 1, d - 1)));
		}
		sort(begin(v), end(v));
		bool a[20000] = {true};
		int c = 1;
		for (int i = 0; i < m; i++) {
			int s, d;
			s = v[i].second.first;
			d = v[i].second.second;
			if (a[s] && !a[d]) {
				a[d] = true;
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}
