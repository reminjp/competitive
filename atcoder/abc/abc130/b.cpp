#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> d(n);
  for (auto& e : d) cin >> e;
  for (int i = 0; i + 1 < n; i++) d[i + 1] += d[i];
  cout << int(upper_bound(begin(d), end(d), x) - begin(d)) + 1 << endl;
}
