#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(int l, int r) {
  ll s = r - l;
  return s * (s + 1) / 2;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    // cerr << bitset<20>(e) << endl;
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<int> s(n + 1), x(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
    x[i + 1] = x[i] ^ a[i];
  }
  vector<pair<int, int>> p;
  int l = 0, r = 1;
  while (r + 1 < n + 1) {
    while (r + 1 < n + 1 && s[r + 1] - s[l] == (x[r + 1] ^ x[l])) {
      r++;
    }
    p.push_back(make_pair(l, r));
    l++;
  }
  // for (auto e : p) {
  //   cerr << e.first << " " << e.second << endl;
  // }

  ll c = 0;
  for (int i = 0; i < p.size(); i++) {
    c += f(p[i].first, p[i].second);
    if (i != 0 && p[i].first < p[i - 1].second) {
      c -= f(p[i].first, p[i - 1].second);
    }
  }
  cout << c << endl;
  return 0;
}
