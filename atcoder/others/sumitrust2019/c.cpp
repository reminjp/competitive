#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  vector<bool> dp(x + 105 + 1);
  dp[0] = true;
  for (int i = 0; i < x; i++) {
    for (int k = 100; k <= 105; k++) {
      dp[i + k] = dp[i + k] || dp[i];
    }
  }
  cout << int(dp[x]) << endl;
}
