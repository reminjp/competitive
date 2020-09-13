#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  for (int k = 0; k < 2; k++) {
    for (int i = 0, j = 1; i < n; i++, j = max(j, i + 1)) {
      if (a[i] != b[i]) continue;
      while (j < n && a[i] == b[j]) j++;
      if (j == n) break;
      swap(b[i], b[j]);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
  }

  // for (auto e : a) cerr << e << ' ';
  // cerr << endl;
  // for (auto e : b) cerr << e << ' ';
  // cerr << endl;

  bool r = true;
  for (int i = 0; i < n; i++) r = r && a[i] != b[i];

  if (r) {
    cout << "Yes" << endl;
    for (auto e : b) cout << e << ' ';
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}
