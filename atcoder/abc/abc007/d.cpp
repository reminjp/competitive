#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a) {
	vector<int> v;
	for (ll i = a; i; i /= 10) {
		v.push_back(i % 10);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 4 || v[i] == 9) {
			v[i]--;
			for (i--; i >= 0; i--) {
				v[i] = 8;
			}
		}
	}
	ll b = 0;
	for (auto it = rbegin(v); it != rend(v); it++) {
		b = 8 * b + *it - (4 < *it);
	}
	return a - b;
}

int main() {
	ll a, b;
	cin >> a >> b;
	cout << f(b) - f(a - 1) << endl;
	return 0;
}
