#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a, ll b) {
	ll r;
	if (b % a) {
		r = 2 * (b / a) * a + f(b % a, a);
	} else {
		r = (2 * (b / a) - 1) * a;
	}
	return r;
}

int main() {
	ll n, x;
	cin >> n >> x;
	cout << n + f(x, n - x) << endl;
	return 0;
}
