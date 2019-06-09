#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (auto& e : w) cin >> e;
  for (int i = 0; i + 1 < n; i++) w[i + 1] += w[i];
  int r = 1e9;
  for (int i = 0; i + 1 < n; i++) r = min(r, abs(w[i] - (w[n - 1] - w[i])));
  cout << r << endl;
}
