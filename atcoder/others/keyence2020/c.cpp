#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  vector<int> r(n, s == (int)1e9 ? 1 : (int)1e9);
  fill(r.begin(), r.begin() + k, s);
  for (auto e : r) cout << e << ' ';
  cout << endl;
}
