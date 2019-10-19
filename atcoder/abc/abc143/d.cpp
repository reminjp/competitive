#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (auto& e : l) cin >> e;
  sort(l.begin(), l.end());
  ll r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int b = lower_bound(l.begin() + (j + 1), l.end(), l[i] + l[j]) - l.begin() - 1;
      if (b < n) r += b - j;
    }
  }
  cout << r << endl;
}
