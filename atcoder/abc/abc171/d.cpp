#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<ll, int> m;
  ll s = 0;
  while (n--) {
    int e;
    cin >> e;
    m[e]++;
    s += e;
  }

  int q;
  cin >> q;
  while (q--) {
    ll b, c;
    cin >> b >> c;
    if (m.count(b)) {
      s += m[b] * (c - b);
      m[c] += m[b];
      m.erase(b);
    }
    cout << s << endl;
  }
}
