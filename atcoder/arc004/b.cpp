#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int s = 0, m = 0;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		s += d;
		m = max(m, d);
	}
	cout << s << endl;
	cout << (m < s - m ? 0 : 2 * m - s) << endl;
	return 0;
}
