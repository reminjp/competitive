#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto &e : v) {
		cin >> e;
	}
	set<string> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				s.insert(v[i] + v[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s.count(v[i])) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}
