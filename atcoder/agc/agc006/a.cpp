#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int i;
	for (i = n; i > 0; i--) {
		int j;
		for (j = 0; j < i && s[n - i + j] == t[j]; j++) {
		}
		if (j == i) {
			break;
		}
	}
	cout << 2 * n - i << endl;
	return 0;
}
