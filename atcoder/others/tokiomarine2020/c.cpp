#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  for (int i = 0; i < k; i++) {
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
      b[max(0, j - a[j])]++;
      if (j + a[j] + 1 < n) b[j + a[j] + 1]--;
    }
    bool f = b[0] == n;
    for (int j = 0; j + 1 < n; j++) b[j + 1] += b[j];
    a = b;
    if (f) break;
  }

  for (auto e : a) cout << e << ' ';
  cout << endl;
}
