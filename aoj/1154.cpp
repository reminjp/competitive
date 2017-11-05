#include <bits/stdc++.h>
using namespace std;

bool ms(int n) {
	return n % 7 == 1 || n % 7 == 6;
}

int main() {
	vector<bool> a(300000, true);
	for (int i = 2; i < 300000; i++) {
		if (a[i]) {
			for (int j = 2 * i; j < 300000; j += i) {
				a[j] = a[j] && !(j % i) && !ms(j / i);
			}
		}
	}
	int n;
	while (cin >> n, n > 1) {
		set<int> s;
		for (int i = 2; i <= n; i++) {
			if (a[i] && !(n % i) && ms(n / i)) {
				s.insert(i);
			}
		}
		cout << n << ":";
		for (auto it = begin(s); it != end(s); it++) {
			cout << " " << *it;
		}
		cout << endl;
	}
	return 0;
}
