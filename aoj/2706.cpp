#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int p, q;
	cin >> p >> q;
	p = gcd(p, q);
	q /= p;
	set<int> s;
	for (int i = 2; i <= q;) {
		if (i * i > q) {
			i = q;
		}
		if (q % i == 0) {
			q /= i;
			s.insert(i);
		} else {
			i++;
		}
	}
	int r = 1;
	for (auto it = begin(s); it != end(s); it++) {
		r *= *it;
	}
	cout << r << endl;
	return 0;
}
