#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int s = a + b + c;
	int m = max(a, max(b, c));
	int t = m + (s % 2 != 3 * m % 2);
	cout << (3 * t - s) / 2 << endl;
	return 0;
}
