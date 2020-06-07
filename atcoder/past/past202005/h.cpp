#include <bits/stdc++.h>
using namespace std;

template <class T>
inline void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int n, l, t1, t2, t3;
  cin >> n >> l;
  vector<bool> h(l + 1);
  while (n--) {
    int x;
    cin >> x;
    h[x] = true;
  }
  cin >> t1 >> t2 >> t3;

  vector<int> dp(l + 5, 1e9);
  dp[0] = 0;
  for (int i = 0; i < l; i++) {
    set_if_less(dp[i + 1], dp[i] + t1 + (h[i + 1] ? t3 : 0));
    set_if_less(dp[i + 2], dp[i] + t1 + t2 + (h[i + 2] ? t3 : 0));
    set_if_less(dp[i + 4], dp[i] + t1 + 3 * t2 + (h[i + 4] ? t3 : 0));
  }

  int r = dp[l];
  if (l - 1 >= 0) set_if_less(r, dp[l - 1] + t1 / 2 + t2 / 2);
  if (l - 2 >= 0) set_if_less(r, dp[l - 2] + t1 / 2 + t2 / 2 + t2);
  if (l - 3 >= 0) set_if_less(r, dp[l - 3] + t1 / 2 + t2 / 2 + 2 * t2);
  cout << r << endl;
}
