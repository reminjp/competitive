#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a[4], n;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> n;
	for (int i = 1; i < 4; i++) {
		a[i] = min(a[i], a[i - 1] << 1);
	}
	n <<= 2;
	ll s = 0;
	for (int i = 4 - 1; i >= 0; i--) {
		s += n / (1 << i) * a[i];
		n %= (1 << i);
	}
	cout << s << endl;
	return 0;
}
