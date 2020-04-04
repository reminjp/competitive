#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  vector<int> l(n), r(n), lt(n, -1e9), rt(n, 1e9);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      l[i] = 1;
      lt[i] = i;
      i += c;
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    l[i + 1] += l[i];
    lt[i + 1] = max(lt[i + 1], lt[i]);
  }

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'o') {
      r[i] = 1;
      rt[i] = i;
      i -= c;
    }
  }
  for (int i = n - 1; i - 1 >= 0; i--) {
    r[i - 1] += r[i];
    rt[i + 1] = max(rt[i - 1], rt[i]);
  }

  for (int i = 0; i < n; i++) {
    if (s[i] != 'o') continue;
    int s = 0, lti = -1e9, rti = 1e9;
    if (i - 1 >= 0) {
      s += l[i - 1];
      lti = lt[i - 1];
    }
    if (i + 1 < n) {
      s += r[i + 1];
      rti = rt[i + 1];
    }
    if (s < k || (s == k && rti - lti - 1 < c)) cout << i + 1 << '\n';
  }
  cout << flush;
}
