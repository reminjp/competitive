// 2016-12-01
#include <iostream>
using namespace std;

int main() {
	int n, q, m, d;
	while (cin >> n >> q, n) {
		int c[100] = {};
		for (int i = 0; i < n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				cin >> d;
				c[d]++;
			}
		}
		int x = 0;
		for (int i = 1; i < 100; i++) {
			if (c[i] >= q && c[i] > c[x]) {
				x = i;
			}
		}
		cout << x << endl;
	}
	return 0;
}
