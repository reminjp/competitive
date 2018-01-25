#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int main() {
	int n;
	cin >> n;
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
	REP(i, n)
	REP(j, n) {
		cin >> d[i + 1][j + 1];
	}
	REP(i, n)
	REP(j, n) {
		d[i + 1][j + 1] += d[i][j + 1] + d[i + 1][j] - d[i][j];
	}
	vector<int> m(n * n + 1);
	REP(i, n)
	REP(j, n)
	REP(k, n - i)
	REP(l, n - j) {
		int t = (k + 1) * (l + 1);
		int s = d[i + k + 1][j + l + 1] - d[i + k + 1][j] - d[i][j + l + 1] + d[i][j];
		m[t] = max(m[t], s);
	}
	REP(i, n * n) {
		m[i + 1] = max(m[i], m[i + 1]);
	}
	int q;
	cin >> q;
	REP(i, q) {
		int p;
		cin >> p;
		cout << m[p] << endl;
	}
	return 0;
}
