#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(3), b(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(begin(a), end(a));
	int m = 0;
	while (a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
		m++;
		b[0] = (a[1] + a[2]) / 2;
		b[1] = (a[2] + a[0]) / 2;
		b[2] = (a[0] + a[1]) / 2;
		sort(begin(b), end(b));
		if (equal(cbegin(a), cend(a), cbegin(b))) {
			m = -1;
			break;
		}
		a = b;
	}
	cout << m << endl;
	return 0;
}
