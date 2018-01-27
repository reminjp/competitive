#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string r;
	cin >> n >> r;
	int s = 0;
	for (auto c : r) {
		s += max(0, 'E' - c);
	}
	cout << fixed << setprecision(9) << (double)s / n << endl;
	return 0;
}
