#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  for (auto& e : h) cin >> e;

  sort(h.rbegin(), h.rend());
  ll r = 0;
  for (int i = k; i < n; i++) r += h[i];
  cout << r << endl;
}
