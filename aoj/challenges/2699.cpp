// 2016-12-02
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int d, e, x, y;
	float m;
	while (cin >> d >> e, d) {
		for (x = 0, y = d, m = abs(d - e); x <= d / 2; x++, y--) {
			m = min(m, (float)fabs(sqrt(x * x + y * y) - e));
		}
		cout  << fixed << setprecision(4) << m << endl;
	}
	return 0;
}
