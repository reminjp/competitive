#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  for (int i = 0; i < n - 1; i++) {
    a[i + 1] += a[i];
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) {
      r = a[i] < x && i == n - 1 ? i : i + 1;
    }
  }
  cout << r << endl;
}
