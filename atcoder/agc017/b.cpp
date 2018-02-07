#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	b -= a;
	bool r = false;
	for (ll i = 0; i <= n - 1; i++) {
		r |= c * i - d * (n - 1 - i) <= b && b <= d * i - c * (n - 1 - i);
	}
	cout << (r ? "YES" : "NO") << endl;
	return 0;
}
