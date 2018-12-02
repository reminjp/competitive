// 2016-12-06
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const int c[4] = {10, 50, 100, 500};
	int n, a[4];
	bool l = false;
	while (cin >> n, n) {
		int m = 0;
		for (int i = 0; i < 4; i++) {
			cin >> a[i];
			m += a[i] * c[i];
		}
		m -= n;
		int b[4];
		for (int i = 3; i >= 0; i--) {
			b[i] = m / c[i];
			m %= c[i];
		}
		if (l) {
			cout << endl;
		}
		l = true;
		for (int i = 0; i < 4; i++) {
			if (b[i] < a[i]) {
				cout << c[i] << ' ' << a[i] - b[i] << endl;
			}
		}
	}
	return 0;
}
