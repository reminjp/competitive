#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = 0, m = 0;
	for (auto c : s) {
		if (c == 'S') {
			n++;
		} else if (n) {
			n--;
		} else {
			m++;
		}
	}
	cout << n + m << endl;
	return 0;
}
