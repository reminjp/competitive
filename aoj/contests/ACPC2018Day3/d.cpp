#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (auto& e : w) {
    string s;
    cin >> s;
    e = s.front() - 'a';
  }
  vector<int> dp(26, 1e9);
  dp[w.front()] = 1;
  for (int i = 1; i < w.size(); i++) {
    dp[w[i]] = min(dp[w[i]], dp[w[i - 1]] + 1);
  }
  cout << dp[w.back()] << endl;
}
