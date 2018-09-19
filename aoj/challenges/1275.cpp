#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, m;
	while (cin >> n >> k >> m, n) {
		vector<int> v(n);
		iota(begin(v), end(v), 1);
		int i = m - 1;
		while (v.size() > 1) {
			v.erase(begin(v) + i);
			i = (i + k - 1) % v.size();
		}
		cout << v[0] << endl;
	}
	return 0;
}
