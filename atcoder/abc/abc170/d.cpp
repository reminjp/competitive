#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1e6;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  int r = 0;
  vector<bool> v(MAX + 1, true);
  for (int i = 0; i < n; i++) {
    if (!v[a[i]]) continue;
    if (i == n || a[i] != a[i + 1]) r++;
    for (int j = a[i]; j <= (int)MAX; j += a[i]) v[j] = false;
  }
  cout << r << endl;
}
