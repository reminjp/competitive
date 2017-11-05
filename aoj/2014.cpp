#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int w, h;
int a[50][50];
bool b[2][50][50];

void f(int c, int i, int j) {
	b[c][i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (i + dy[k] >= 0 && i + dy[k] < h && j + dx[k] >= 0 && j + dx[k] < w) {
			if (a[i + dy[k]][j + dx[k]] == -1 && !b[c][i + dy[k]][j + dx[k]]) {
				f(c, i + dy[k], j + dx[k]);
			}
		}
	}
}

int main() {
	while (cin >> w >> h, w) {
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < w; j++) {
				if (s[j] == 'B') {
					a[i][j] = 0;
				} else if (s[j] == 'W') {
					a[i][j] = 1;
				} else {
					a[i][j] = -1;
				}
			}
		}
		for (int c = 0; c < 2; c++) {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					b[c][i][j] = false;
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] != -1) {
					f(a[i][j], i, j);
				}
			}
		}
		int p = 0, q = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == -1) {
					if (b[0][i][j] && !b[1][i][j]) {
						p++;
					} else if (!b[0][i][j] && b[1][i][j]) {
						q++;
					}
				}
			}
		}
		cout << p << ' ' << q << endl;
	}
	return 0;
}
