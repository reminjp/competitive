#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;

int main() {
	int r, c, x, y, d, l;
	cin >> r >> c >> x >> y >> d >> l;
	vector<vector<ll>> C(x * y + 1, vector<ll>(x * y + 1, 1));
	for (int i = 2; i <= x * y; i++) {
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	ll n = 0;
	for (int top = 0; top < 2; top++) {
		for (int bottom = 0; bottom < 2; bottom++) {
			for (int left = 0; left < 2; left++) {
				for (int right = 0; right < 2; right++) {
					if (0 < x - top - bottom && 0 < y - left - right && d + l <= (x - top - bottom) * (y - left - right)) {
						ll t = C[(x - top - bottom) * (y - left - right)][d + l] * C[d + l][d] % mod;
						if ((top + bottom + left + right) % 2) {
							n = (mod + n - t) % mod;
						} else {
							n = (n + t) % mod;
						}
					}
				}
			}
		}
	}
	n = n * (r - x + 1) * (c - y + 1) % mod;
	cout << n << endl;
	return 0;
}
