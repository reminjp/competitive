#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int t[16][17];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + 1; j++) {
				cin >> t[i][j];
			}
		}
		int dp[1 << 16];
		dp[0] = 0;
		for (int i = 1; i < 1 << n; i++) {
			dp[i] = 1000000000;
			for (int j = 0; j < n; j++) {
				if (i & 1 << j) {
					dp[i] = min(dp[i], dp[i ^ 1 << j] + t[j][0]);
					for (int k = 0; k < n; k++) {
						if ((i ^ 1 << j) & 1 << k) {
							dp[i] = min(dp[i], dp[i ^ 1 << j] + t[j][k + 1]);
						}
					}
				}
			}
		}
		cout << dp[(1 << n) - 1] << endl;
	}
	return 0;
}
