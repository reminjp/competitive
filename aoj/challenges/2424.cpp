// 2016-12-12
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int q, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		int c = 0;
		while (n >= 10) {
			int m = 0;
			for (int j = 10; j <= n; j *= 10) {
				m = max(m, (n / j) * (n % j));
			}
			n = m;
			c++;
		}
		cout << c << endl;
	}
	return 0;
}
