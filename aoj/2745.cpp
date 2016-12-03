// 2016-12-04
#include <iostream>
using namespace std;

int main() {
	int r0, w0, c, r;
	while (cin >> r0 >> w0 >> c >> r, r0) {
		int s = w0 * c - r0;
		if (s > 0) {
			cout << (s - 1) / r + 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
