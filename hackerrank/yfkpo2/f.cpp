#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  string s;
  cin >> n >> s >> m;
  vector<ll> q(m);
  for (auto &e : q) {
    cin >> e;
    e--;
  }

  vector<ll> l(n);
  for (ll i = 1; i < n; i++) l[i] = l[i - 1] + i;
  for (auto e : q) cout << s[e - *(upper_bound(begin(l), end(l), e) - 1)] << endl;
}
