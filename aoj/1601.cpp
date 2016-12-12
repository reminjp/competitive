// 2016-12-12
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t[5] = {5, 7, 5, 7, 7};
	int n, a[40];
	string s;
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			a[i] = s.length();
		}
		bool b = false;
		for (int i = 0; i < n; i++) {
			for (int j = i, k = 0, m = 0; j < n; j++) {
				m += a[j];
				if (m == t[k]) {
					k++;
					m = 0;
					if (k == 5) {
						b = true;
						break;
					}
				} else if (m > t[k]) {
					break;
				}
			}
			if (b) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
