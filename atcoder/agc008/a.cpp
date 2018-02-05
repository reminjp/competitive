#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int m = INT_MAX;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int a = i ? -x : x, b = j ? -y : y;
			if (a <= b) {
				m = min(m, i + j + b - a);
			}
		}
	}
	cout << m << endl;
	return 0;
}
