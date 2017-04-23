// 2017-04-23
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> p;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			p.push_back(a[i] * a[j]);
		}
	}
	int m = -1;
	for (auto i = begin(p); i != end(p); i++) {
		int v = *i;
		int d = v % 10;
		v /= 10;
		while (v > 0) {
			if (v % 10 != d - 1) {
				break;
			}
			d = v % 10;
			v /= 10;
		}
		if (v == 0) {
			m = max(m, *i);
		}
	}
	cout << m << endl;
	return 0;
}
