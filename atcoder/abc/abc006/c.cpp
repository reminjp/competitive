#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a, b, c;
	if (2 * n <= m && m <= 4 * n) {
		a = m / 2 - m % 2;
		b = m % 2;
		c = max(0, a + b - n);
		a -= 2 * c;
	} else {
		a = b = c = -1;
	}
	cout << a << " " << b << " " << c << endl;
	return 0;
}
