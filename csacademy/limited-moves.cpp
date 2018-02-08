#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int m = 0; m < 500; m++) {
		int r = 1;
		while (!(r & n)) {
			r <<= 1;
		}
		cout << r << endl;
		n -= r;
		cin >> r;
		n -= r;
	}
	return 0;
}
