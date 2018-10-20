#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> l(2 * n);
	for (auto& e : l) {
		cin >> e;
	}
	sort(begin(l), end(l));
	int m = 0;
	for (int i = 0; i < n; i++) {
		m += l[2 * i];
	}
	cout << m << endl;
	return 0;
}
