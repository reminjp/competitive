// 2016-12-12
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n, v[100];
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			v[i] = c - 'A';
		}
		pair<int, int> a[26];
		for (int i = 0; i < 26; i++) {
			a[i] = make_pair(0, i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				if (v[i] == a[j].second) {
					a[j].first++;
					break;
				}
			}
			sort(a, a + 26);
			if (a[25].first - a[24].first > n - i - 1) {
				cout << char(a[25].second + 'A') << ' ' << i + 1 << endl;
				break;
			}
		}
		if (a[25].first == a[24].first) {
			cout << "TIE" << endl;
		}
	}
	return 0;
}
