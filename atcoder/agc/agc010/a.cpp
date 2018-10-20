#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m += a % 2;
	}
	cout << (m % 2 ? "NO" : "YES") << endl;
	return 0;
}
