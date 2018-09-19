// 2016-11-25
#include <iostream>
using namespace std;

int main() {
	int n, m, p;
	int x[100];
	int s;
	float a;
	cin >> n >> m >> p;
	while (n || m || p) {
		s = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			s += x[i];
		}
		if (x[m - 1] == 0) {
			cout << 0 << endl;
		} else {
			a = 100 * s;
			a *= (1.0 - 0.01 * p);
			a /= x[m - 1];
			cout << (int)a << endl;
		}
		cin >> n >> m >> p;
	}
	return 0;
}
