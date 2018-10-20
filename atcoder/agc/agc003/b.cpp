#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long m = 0;
	for (int i = 0; i < n; i++) {
		m += a[i] / 2;
		a[i] %= 2;
		if (a[i] && a[i + 1]) {
			m++;
			a[i]--;
			a[i + 1]--;
		}
	}
	cout << m << endl;
	return 0;
}
