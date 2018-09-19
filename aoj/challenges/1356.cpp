// 2017-03-13
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool b[100000] = {};
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			b[0] = true;
			continue;
		}
		int d = 0;
		int m = min(n, i + 5);
		for (int j = i; j < m; j++) {
			d = 10 * d + a[j];
			b[d] = true;
		}
	}
	for (int i = 0; i < 100000; i++) {
		if (!b[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
