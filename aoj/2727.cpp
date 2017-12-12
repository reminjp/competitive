#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<string> v(2);
	for (int i = 0; i < s.size(); i++) {
		v[i % 2].push_back(s[i]);
	}
	bool r = false;
	for (auto e : v) {
		int i, j;
		for (i = 0, j = 0; i < e.size() && j < t.size(); j++) {
			if (e[i] == t[j]) {
				i++;
			}
		}
		if (i == e.size()) {
			r = true;
			break;
		}
	}
	cout << (r ? "Yes" : "No") << endl;
	return 0;
}
