#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int s = x;
  for (auto e : a) {
    if (e != -1) s ^= e;
  }
  for (auto& e : a) {
    if (e != -1) continue;
    e = s;
    for (int i = 0; e > x && (e >> i) != 0; i++) {
      if ((e >> i) & 1) e ^= 1 << i;
    }
    s ^= e;
  }
  if (s == 0) {
    for (auto e : a) cout << e << ' ';
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
