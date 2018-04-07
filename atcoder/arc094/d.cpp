#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int q;
	cin >> q;
	for (; q > 0; q--) {
		ll a, b;
		cin >> a >> b;
		if (a * b <= 2) {
			cout << 0 << endl;
			continue;
		}
		if (a > b) {
			ll t = a;
			a = b;
			b = t;
		}

		ll r = sqrt(a * b);
		ll x = r + (r == a), y = r + 1 + (r + 1 == b);
		while (x * y >= a * b) {
			if (x < y || (x - 1 == a && x == 2)) {
				if (y - 1 != b) {
					y -= 1;
				} else if (y > 2) {
					y -= 2;
				} else {
					break;
				}
			} else {
				if (x - 1 != a) {
					x -= 1;
				} else {
					x -= 2;
				}
			}
		}
		// cerr << x << " " << y << endl;
		cout << (x - (a < x)) + (y - 1 - (b < y)) << endl;
	}
	return 0;
}
