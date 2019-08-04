#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto& e : h) cin >> e;

  bool r = true;
  for (int i = 0, b = true; i + 1 < n; i++) {
    if (h[i] < h[i + 1]) {
      b = true;
    } else if (h[i] > h[i + 1]) {
      if (b && h[i] - 1 == h[i + 1]) {
        b = false;
      } else {
        r = false;
        break;
      }
    }
  }
  cout << (r ? "Yes" : "No") << endl;
}
