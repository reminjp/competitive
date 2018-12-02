// 2016-12-12
#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n, p;
	bool a[100275];
	fill(a, a + 100275, true);
	a[0] = a[1] = false;
	vector<int> v;
	for (int i = 2; i < 100275; i++) {
		if (a[i]) {
			v.push_back(i);
			for (int j = i + i; j < 100275; j += i) {
				a[j] = false;
			}
		}
	}
	vector<pair<int, int>> w;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i, l = min((int)v.size(), i + 50); j < l; j++) {
			if (v[i] + v[j] > 200274) {
				break;
			} else {
				w.push_back(make_pair(v[i] + v[j], min(v[i], v[j])));
			}
		}
	}
	sort(begin(w), end(w));
	while (cin >> n >> p, n >= 0) {
		int i, m;
		for (i = 0, m = 0; i < w.size(); i++) {
			if (w[i].second > n) {
				m++;
				if (m >= p) {
					break;
				}
			}
		}
		cout << w[i].first << endl;
	}
	return 0;
}
