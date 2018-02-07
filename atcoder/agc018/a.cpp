#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& e : a) {
		cin >> e;
	}
	int d = a.front();
	for (auto e : a) {
		d = gcd(d, e);
	}
	bool r = false;
	for (auto e : a) {
		r |= k <= e && (e - k) % d == 0;
	}
	cout << (r ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}
