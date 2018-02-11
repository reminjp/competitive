#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, k;
	cin >> x >> k;
	int d = 1;
	for (int i = 0; i < k; i++) {
		d *= 10;
	}
	cout << (x / d + 1) * d << endl;
	return 0;
}
