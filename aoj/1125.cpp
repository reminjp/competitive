// 2016-12-01
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, w, h, s, t;
	int x[500], y[500];
	int c[100][100];
	while (cin >> n, n) {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				c[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			x[i]--; y[i]--;
		}
		cin >> s >> t;
		for (int i = 0; i < n; i++) {
			for (int j = max(0, y[i] - t + 1), jj = min(h, y[i] + 1); j < jj; j++) {
				for (int k = max(0, x[i] - s + 1), kk = min(w, x[i] + 1); k < kk; k++) {
					c[j][k]++;
				}
			}
		}
		int m = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				m = max(m, c[i][j]);
			}
		}
		cout << m << endl;
	}
	return 0;
}
