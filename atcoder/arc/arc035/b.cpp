#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (auto& e : t) cin >> e;
  sort(t.begin(), t.end());

  ll p = 0, r = 1, s = 0, l = 0;
  for (int i = 0; i < n; i++) {
    s += t[i];
    p += s;

    if (i - 1 >= 0 && t[i - 1] == t[i]) {
      l++;
    } else {
      l = 1;
    }
    r *= l;
    r %= MOD;
  }
  cout << p << '\n' << r << endl;
}
