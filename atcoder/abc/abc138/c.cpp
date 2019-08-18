#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v) cin >> e;
  sort(begin(v), end(v));
  double r = v.front();
  for (auto e : v) r = (r + e) / 2.0;
  cout << fixed << setprecision(6) << r << endl;
}
