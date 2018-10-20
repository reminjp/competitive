#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e4 + 7;

int main() {
	int n;
	cin >> n;
	n--;
	int a[3] = {0, 0, 1};
	while (3 <= n) {
		int t = (a[0] + a[1] + a[2]) % mod;
		a[0] = a[1];
		a[1] = a[2];
		a[2] = t;
		n--;
	}
	cout << a[n] << endl;
	return 0;
}
