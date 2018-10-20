#include <bits/stdc++.h>
using namespace std;

int main() {
	int h = 4, w = 4;
	vector<vector<char>> c(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			string s;
			cin >> s;
			c[i][j] = s[0];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << c[h - i - 1][w - j - 1] << " \n"[j == w - 1];
		}
	}
	cout << flush;
	return 0;
}
