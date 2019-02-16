#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> costs = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto& e : a) {
    cin >> e;
  }
  vector<string> dp(n + 7, ".");
  dp[0] = "";
  for (int i = 0; i < n; i++) {
    if (dp[i] == ".") {
      continue;
    }
    string s = dp[i];
    for (auto e : a) {
      s.push_back('0' + e);
      const string& t = dp[i + costs[e - 1]];
      if (s.size() > t.size() || s.size() == t.size() && s > t) {
        dp[i + costs[e - 1]] = s;
      }
      s.pop_back();
    }
  }
  cout << dp[n] << endl;
}
