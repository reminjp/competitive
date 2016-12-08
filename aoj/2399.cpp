// 2016-12-08
#include <iostream>
using namespace std;

int main() {
	int n, m, p, k, l;
	bool a[100], b[100][100];
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = false;
			}
			a[i] = true;
		}
		for (int i = 0; i < n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				cin >> p;
				b[i][p - 1] = true;
			}
		}
		cin >> k;
		for (int i = 0; i < k; i ++) {
			cin >> l;
			for (int j = 0; j < n; j++) {
				a[j] &= b[j][l - 1];
			}
		}
		int r, c = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				r = i + 1;
				c++;
			}
		}
		if (c != 1) {
			r = -1;
		}
		cout << r << endl;
	}
	return 0;
}
