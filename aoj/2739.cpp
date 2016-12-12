// 2016-12-12
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m, t, a;
	cin >> n >> m >> t;
	int s = 0, u = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s += max(0, (a - m) - u);
		u = a + m;
	}
	s += max(0, t - u);
	cout << s << endl;
	return 0;
}
