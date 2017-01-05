#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	bool f[60] = {};
	cin >> a >> b >> c;
	for (int t = c; ; t += 60) {
		int d = t % (a + b);
		if (d <= a) {
			cout << t << endl;
			break;
		} else if (f[d]) {
			cout << -1 << endl;
			break;
		}
		f[d] = true;
	}
	return 0;
}
