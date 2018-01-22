#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n, make_pair(0, 0)), u;
	for (auto& e : v) {
		string s;
		cin >> s;
		e.first = (10 * (6 * (10 * (s[0] - '0') + (s[1] - '0')) + (s[2] - '0')) + (s[3] - '0')) / 5 * 5;
		e.second = ((10 * (6 * (10 * (s[5] - '0') + (s[6] - '0')) + (s[7] - '0')) + (s[8] - '0') - 1) / 5 + 1) * 5;
	}
	sort(begin(v), end(v));
	u.push_back(v.front());
	for (auto e : v) {
		if (e.first <= u.back().second) {
			u.back().second = max(u.back().second, e.second);
		} else {
			u.push_back(e);
		}
	}
	for (auto e : u) {
		cout << e.first / 10 / 6 / 10 << e.first / 10 / 6 % 10 << e.first / 10 % 6 << e.first % 10 << "-";
		cout << e.second / 10 / 6 / 10 << e.second / 10 / 6 % 10 << e.second / 10 % 6 << e.second % 10 << endl;
	}
	return 0;
}
