#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int r = 0;
  for (auto e : a) {
    if (e == r + 1) r++;
  }
  cout << (r == 0 ? -1 : n - r) << endl;
}
