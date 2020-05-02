#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int q;
  cin >> q;
  queue<pair<char, int>> a;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      char c;
      int x;
      cin >> c >> x;
      a.push({c, x});
    } else {
      int d;
      cin >> d;

      map<char, ll> m;
      while (d > 0 && !a.empty()) {
        int c = min(d, a.front().second);
        d -= c;
        a.front().second -= c;
        m[a.front().first] += c;
        if (a.front().second == 0) a.pop();
      }

      ll r = 0;
      for (const auto &e : m) r += e.second * e.second;
      cout << r << endl;
    }
  }
}
