#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (auto& e : a) cin >> e;
  b = a;
  sort(begin(b), end(b));
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += a[i] != b[i];
  }
  cout << (r <= 2 ? "YES" : "NO") << endl;
}
