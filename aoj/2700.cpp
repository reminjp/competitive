// 2017-02-03
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector<string> v;
		int l = 0;
		for (int i = 0; i < n; i++) {
			string s, t;
			cin >> s;
			t.push_back(s[0]);
			for (int j = 1; j < s.length(); j++) {
				switch (s[j - 1]) {
					case 'a': case 'i': case 'u': case 'e': case 'o': t.push_back(s[j]);
				}
			}
			v.push_back(t);
			l = max(l, (int)t.length());
		}
		sort(begin(v), end(v));
		for (int i = 0; i < n; i++) {
			while (v[i].length() < l) v[i].push_back('.');
		}
		int d = -1;
		bool b[50] = {};
		for (int i = 0; i < l; i++) {
			bool a = true;
			for (int j = 1; j < n; j++) {
				if (v[j][i] != v[j - 1][i]) b[j] = true;
				a &= b[j];
			}
			if (a) {
				d = i + 1;
				break;
			}
		}
		cout << d << endl;
	}
	return 0;
}
