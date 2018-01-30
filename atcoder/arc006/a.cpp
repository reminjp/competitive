#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> e(10), b(10), l(10);
	int x;
	for (int i = 0; i < 6; i++) {
		cin >> x;
		e[x]++;
		b[x]++;
	}
	cin >> x;
	b[x]++;
	for (int i = 0; i < 6; i++) {
		cin >> x;
		l[x]++;
	}
	int m = 0, n = 0;
	for (int i = 0; i < 10; i++) {
		m += min(e[i], l[i]);
		n += min(b[i], l[i]);
	}
	cout << (7 - m + (n != 6)) % 6 << endl;
	return 0;
}
