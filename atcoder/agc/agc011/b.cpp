#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& e : a) {
		cin >> e;
	}
	sort(begin(a), end(a));
	vector<ll> s(n + 1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}
	int m = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= 2 * s[i]) {
			m++;
		} else {
			break;
		}
	}
	cout << m << endl;
	return 0;
}
