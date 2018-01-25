#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	vector<vector<int>> dp(2000 + 1, vector<int>(r + g + b + 1));
	fill(begin(dp[0]), end(dp[0]), (int)1e9);
	dp[0][0] = 0;
	for (int i = 1; i <= 2000; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j <= min(i, r + g + b); j++) {
			int c;
			if (j <= r) {
				c = abs(i - (1000 - 100));
			} else if (j <= r + g) {
				c = abs(i - 1000);
			} else {
				c = abs(i - (1000 + 100));
			}
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + c);
		}
	}
	cout << dp[2000][r + g + b] << endl;
	return 0;
}
