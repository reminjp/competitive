#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << min(100 * (n / 10) + 15 * (n % 10), 100 * ((n - 1) / 10 + 1)) << endl;
	return 0;
}
