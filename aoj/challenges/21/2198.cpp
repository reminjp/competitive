#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector<pair<double, string>> v;
		for (int i = 0; i < n; i++) {
			string l;
			int p, a, b, c, d, e, f, s, m;
			cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			v.push_back(make_pair(-double(f * s * m - p) / (a + b + c + m * (d + e)), l));
		}
		sort(begin(v), end(v));
		for (auto it = begin(v); it != end(v); it++) {
			cout << it->second << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}
