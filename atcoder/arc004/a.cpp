#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			m = max(m, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	cout << fixed << setprecision(3) << sqrt(m) << endl;
	return 0;
}
