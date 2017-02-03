// 2017-02-03
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 7368791

int main() {
	int m, n;
	static bool b[MAX];
	while (cin >> m >> n, m) {
		fill(b, b + MAX, false);
		int y = MAX;
		for (int i = m; i < MAX; i++) {
			if (!b[i]) {
				if (n > 0) {
					n--;
					for (int j = i; j < MAX; j += i) b[j] = true;
				} else {
					y = i;
					break;
				}
			}
		}
		cout << y << endl;
	}
	return 0;
}
