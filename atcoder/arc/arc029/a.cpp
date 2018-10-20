#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (auto &e : t) {
    cin >> e;
  }
  int r = 1e9;
  for (int i = 0; i < 1 << n; i++) {
    vector<int> s(2);
    for (int j = 0; j < n; j++) {
      s[i >> j & 1] += t[j];
    }
    r = min(r, max(s[0], s[1]));
  }
  cout << r << endl;
}
