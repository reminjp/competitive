#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& e : a) {
		cin >> e;
	}
	sort(begin(a), end(a));
	int m = -1;
	for (auto it = begin(a); it != end(a) - 1; it++) {
		if (abs(2 * *it - a.back()) < abs(2 * m - a.back())) {
			m = *it;
		}
	}
	cout << a.back() << " " << m << endl;
	return 0;
}
