#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, k;
  cin >> m >> k;

  if (k >= (1 << m)) {
    cout << -1 << endl;
    return 0;
  }
  if (m < 2 && k != 0) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> r;
  if (k == 0) {
    for (int i = 0; i < (1 << m); i++) {
      r.push_back(i);
      r.push_back(i);
    }
  } else {
    for (int i = 0; i < (1 << m); i++) {
      if (i != k) r.push_back(i);
    }
    r.push_back(k);
    for (int i = (1 << m) - 1; i >= 0; i--) {
      if (i != k) r.push_back(i);
    }
    r.push_back(k);
  }

  for (auto e : r) cout << e << " ";
  cout << endl;
}
