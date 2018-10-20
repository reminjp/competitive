#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, v;
	cin >> m;
	if (m < 100) {
		v = 0;
	} else if (m <= 5000) {
		v = m / 100;
	} else if (m <= 30000) {
		v = m / 1000 + 50;
	} else if (m <= 70000) {
		v = (m / 1000 - 30) / 5 + 80;
	} else {
		v = 89;
	}
	cout << (v < 10 ? "0" : "") << v << endl;
	return 0;
}
