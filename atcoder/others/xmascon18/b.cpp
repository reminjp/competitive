#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int k, const string& s, int i, int x, int a, int b, bool f) {
  if (i == s.size()) {
    if (b || !f) {
      return false;
    }
    return x * a == k;
  }

  bool r = false;
  int si = s[i] - '0';
  if (b) {
    ll xt = x * pow(a, b);
    if (xt < k) {
      r |= dfs(k, s, i + 1, xt, si, 0, true);
    }
  } else {
    r |= dfs(k, s, i + 1, x, 10 * a + si, b, f);
  }
  if (a && si) {
    r |= dfs(k, s, i + 1, x, a, 10 * b + si, f);
  }
  return r;
}

int main() {
  set<int> r;
  for (int i = 1; i <= 20181224; i++) {
    if (dfs(i, to_string(i), 0, 1, 0, 0, false)) {
      cerr << i << endl;
      r.insert(i);
    }
  }
  for (auto e : r) {
    cout << e << endl;
  }
}
