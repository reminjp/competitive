#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n), v(n);
  for (auto& e : h) cin >> e;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a] = max(v[a], h[b]);
    v[b] = max(v[b], h[a]);
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] > v[i]) r++;
  }
  cout << r << endl;
}
