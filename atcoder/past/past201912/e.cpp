#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<bitset<100>> f(n);
  for (; q > 0; q--) {
    int s, a, b;
    cin >> s >> a;
    a--;
    if (s == 1) {
      cin >> b;
      b--;
      f[a][b] = true;
    } else if (s == 2) {
      for (int i = 0; i < n; i++) {
        if (f[i][a]) f[a][i] = true;
      }
    } else if (s == 3) {
      bitset<100> t;
      for (int i = 0; i < n; i++) {
        if (f[a][i]) t |= f[i];
      }
      t[a] = false;
      f[a] |= t;
    }
  }

  for (const auto& e : f) {
    auto t = e.to_string('N', 'Y');
    reverse(t.begin(), t.end());
    t.resize(n);
    cout << t << endl;
  }
}
