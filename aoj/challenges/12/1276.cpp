// 2017-02-21
#include <iostream>
using namespace std;
#define N 1299709

int main() {
	static bool a[N + 1] = {true, true};
	static int b[N + 1], c[N + 1];
	{
		int t = 2;
		for (int i = 2; i <= N; i++) {
			if (a[i]) {
				b[i] = t;
			} else {
				c[t] = i - t;
				t = i;
				for (int j = 2 * i; j <= N; j += i) {
					a[j] = true;
				}
			}
		}
	}
	int n;
	while (cin >> n, n) {
		if (a[n]) {
			cout << c[b[n]] << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
