#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int b = 0, t = 1e9, m;
  while (b + 1 < t) {
    m = b + (t - b) / 2;

    int c = 0;
    for (auto e : a) c += (e - 1) / m;

    if (c > k) {
      b = m;
    } else {
      t = m;
    }
  }
  cout << t << endl;
}
