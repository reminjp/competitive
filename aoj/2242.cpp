#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	while (cin >> n >> q, n) {
		vector<pair<pair<int, int>, string>> v;
		for (int i = 0; i < n; i++) {
			string s;
			int a, b;
			cin >> s >> a >> b;
			v.push_back(make_pair(make_pair(b - a, b), s));
		}
		for (int i = 0; i < q; i++) {
			int a;
			cin >> a;
			bool f = false;
			for (auto it = begin(v); it != end(v); it++) {
				if (it->first.first < a && a <= it->first.second) {
					cout << it->second << " " << a - it->first.first << endl;
					f = true;
					break;
				}
			}
			if (!f) {
				cout << "Unknown" << endl;
			}
		}
	}
	return 0;
}
