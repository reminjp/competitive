#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		m += a * b;
	}
	cout << int(m * 1.05) << endl;
	return 0;
}
