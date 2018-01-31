#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, a;
	cin >> m >> n >> a;
	int r = a;
	while (m <= a) {
		r += a / m * n;
		a = a % m + a / m * n;
	}
	cout << r << endl;
	return 0;
}
