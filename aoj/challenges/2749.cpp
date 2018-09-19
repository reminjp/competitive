// 2017-07-13
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n, m, s[15], d[100], sum[1 << 15], dp[1 << 15];
	while (cin >> n >> m, n) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> d[i];
		}
		sort(d, d + m);
		for (int i = 0; i < 1 << n; i++) {
			sum[i] = 0;
			for (int j = 0; j < n; j++) {
				if (i & 1 << j) {
					sum[i] += s[j];
				}
			}
		}
		fill(dp, dp + (1 << n), 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 1 << n; j++) {
				dp[j] += abs(sum[j] - d[i]);
			}
			for (int j = 0; j < 1 << n; j++) {
				for (int k = 0; k < n; k++) {
					dp[j] = min(dp[j], dp[j & ~(1 << k)]);
				}
			}
		}
		cout << dp[(1 << n) - 1] << endl;
	}
	return 0;
}
