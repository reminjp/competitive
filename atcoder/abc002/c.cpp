#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, a, b, c, d;
	cin >> x >> y >> a >> b >> c >> d;
	cout << fixed << setprecision(1) << abs((a - x) * (d - y) - (b - y) * (c - x)) / 2.0 << endl;
	return 0;
}
