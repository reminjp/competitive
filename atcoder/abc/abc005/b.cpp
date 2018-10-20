#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		m = min(m, t);
	}
	cout << m << endl;
	return 0;
}
