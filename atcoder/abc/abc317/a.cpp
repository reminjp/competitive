#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h, x;
  cin >> n >> h >> x;
  vector<int> p(n);
  for (auto& e : p) cin >> e;

  cout << (lower_bound(p.begin(), p.end(), x - h) - p.begin() + 1) << endl;
}
