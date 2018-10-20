#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int m = INT_MAX;
	for (char c = 'a'; c <= 'z'; c++) {
		int k = 0, i = 0;
		for (auto e : s) {
			if (e == c) {
				k = max(k, i);
				i = 0;
			} else {
				i++;
			}
		}
		m = min(m, max(k, i));
	}
	cout << m << endl;
	return 0;
}
