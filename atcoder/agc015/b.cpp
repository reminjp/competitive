#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	long long m = 0;
	for (int i = 0, n = s.size(); i < n; i++) {
		if (s[i] == 'D') {
			m += i + 2 * (n - i - 1);
		} else {
			m += 2 * i + (n - i - 1);
		}
	}
	cout << m << endl;
	return 0;
}
