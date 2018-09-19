// 2017-01-21
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, c;
	cin >> n;
	for (c = 0; n > 1; c++) {
		int a = (n - 1) / 3 + 1;
		n = max(a, n - 2 * a);
	}
	cout << c << endl;
	return 0;
}
