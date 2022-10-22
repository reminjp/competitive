#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> v(n + 1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    v[l]++;
    v[r]--;
  }

  int r = 0, s = 0;
  for (auto e : v) {
    s += e;
    r += s % 2;
  }
  cout << r << endl;
}
