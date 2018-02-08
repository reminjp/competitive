#include <bits/stdc++.h>
using namespace std;

int main() {
	int b = 1, t = 1000001, m;
	while (t - b > 1) {
		m = (b + t) / 2;
		cout << "Q " << m;
		int a;
		cin >> a;
		if (a) {
			b = m;
		} else {
			t = m;
		}
	}
	int n = 0, x = 0;
	while (x < b) {
		n += 5;
		for (int k = n; k % 5 == 0; k /= 5) {
			x++;
		}
	}
	cout << "A " << n << endl;
	return 0;
}
