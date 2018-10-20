#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> a(5);
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < 5; j++) {
			if (t.front() == "MARCH"[j]) {
				a[j]++;
			}
		}
	}
	vector<vector<ll>> dp(6, vector<ll>(6));
	for (int i = 0; i <= 5; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * a[i - 1];
		}
	}
	cout << dp[5][3] << endl;
	return 0;
}
