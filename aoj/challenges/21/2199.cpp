#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;

int main() {
	int n, m;
	while (cin >> n >> m, n) {
		int c[16], x[20000];
		for (int i = 0; i < m; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		vector<vector<int>> dp(n + 1, vector<int>(256, inf));
		dp[0][128] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 256; j++) {
				if (dp[i][j] != inf) {
					for (int k = 0; k < m; k++) {
						int j2 = max(0, min(255, j + c[k]));
						dp[i + 1][j2] = min(dp[i + 1][j2], dp[i][j] + (x[i] - j2) * (x[i] - j2));
					}
				}
			}
		}
		int r = inf;
		for (int i = 0; i < 256; i++) {
			r = min(r, dp[n][i]);
		}
		cout << r << endl;
	}
	return 0;
}
