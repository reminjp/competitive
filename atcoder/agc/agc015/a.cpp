#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll m;
	if (n == 1) {
		m = a == b;
	} else if (b < a) {
		m = 0;
	} else {
		m = ((n - 1) * b + a) - ((n - 1) * a + b) + 1;
	}
	cout << m << endl;
	return 0;
}
