#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b;
	for (auto& e : a) {
		cin >> e;
	}
	b = a;
	sort(begin(b), end(b));
	for (auto e : a) {
		cout << (e < b[n / 2] ? b[n / 2] : b[n / 2 - 1]) << endl;
	}
	return 0;
}
