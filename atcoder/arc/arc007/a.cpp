#include <bits/stdc++.h>
using namespace std;

int main() {
	string x, s, t;
	cin >> x >> s;
	for (auto c : s) {
		if (c != x[0]) {
			t.push_back(c);
		}
	}
	cout << t << endl;
	return 0;
}
