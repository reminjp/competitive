#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<int> d = {5, 10};
	vector<int> dp(abs(a - b) + 1);
	for (int i = 1; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + 1;
		for (auto e : d) {
			if (abs(i - e) < i) {
				dp[i] = min(dp[i], dp[abs(i - e)] + 1);
			}
		}
	}
	cout << dp.back() << endl;
	return 0;
}
