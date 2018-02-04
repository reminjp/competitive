#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int m = 0;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			m += s[j] == '#';
		}
	}
	cout << (m == h + w - 1 ? "Possible" : "Impossible") << endl;
	return 0;
}
