#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(1e5 + 1), s(1e5 + 1);
  for (auto& e : a) cin >> e;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    b[e]++;
  }

  int r = 1e9;
  for (auto e : a) {
    s[e]++;
    r = min(r, b[e] / s[e]);
    cout << r << endl;
  }
}
