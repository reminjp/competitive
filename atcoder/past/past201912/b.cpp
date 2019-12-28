#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  for (int i = 0; i + 1 < n; i++) {
    int d = a[i + 1] - a[i];
    if (d < 0) {
      cout << "down " << -d << '\n';
    } else if (d > 0) {
      cout << "up " << d << '\n';
    } else {
      cout << "stay" << '\n';
    }
  }
  cout << flush;
}
