#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<int> r(n);
  for (int i = 0; i < n; i += 2) {
    if (n - i == 3) {
      r[i] = a[i + 1] + a[i + 2];
      r[i + 1] = -a[i];
      r[i + 2] = -a[i];
      break;
    }
    r[i] = a[i + 1];
    r[i + 1] = -a[i];
  }

  // for (auto e : r) cout << e << ' ';
  // cout << endl;

  for (int i = 0; i < n; i++) cout << r[i] << " \n"[i == n - 1];
}
