#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (auto& e : p) cin >> e;

  vector<double> v(n + 1);
  for (int i = 0; i < n; i++) {
    v[i + 1] = (p[i] + 1) / 2.0;
    v[i + 1] += v[i];
  }
  double r = 0;
  for (int i = 0; i + k < n + 1; i++) {
    r = max(r, v[i + k] - v[i]);
  }
  cout << fixed << setprecision(9);
  cout << r << endl;
}
