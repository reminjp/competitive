#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int h = 100, w = 100;
	vector<vector<bool>> v(h, vector<bool>(w));
	for (int i = 0; i < h / 2; i++) {
		for (int j = 0; j < w; j++) {
			v[i][j] = true;
		}
	}
	for (int i = 0; i < a - 1; i++) {
		v[i / (w / 2) * 2][i % (w / 2) * 2] = false;
	}
	for (int i = 0; i < b - 1; i++) {
		v[h - 1 - i / (w / 2) * 2][w - 1 - i % (w / 2) * 2] = true;
	}
	cout << h << " " << w << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ".#"[v[i][j]];
		}
		cout << endl;
	}
	return 0;
}
