#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int i;
	for (i = 0; i < m; i++) {
		if (n <= a) {
			n += b;
		}
		int c;
		cin >> c;
		n -= c;
		if (n < 0) {
			break;
		}
	}
	if (i < m) {
		cout << i + 1 << endl;
	} else {
		cout << "complete" << endl;
	}
	return 0;
}
