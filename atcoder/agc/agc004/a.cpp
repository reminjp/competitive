#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << min(a % 2 * b * c, min(b % 2 * c * a, c % 2 * a * b)) << endl;
	return 0;
}
