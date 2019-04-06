#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 5, k;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  cin >> k;
  bool r = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r &= abs(a[i] - a[j]) <= k;
    }
  }
  cout << (r ? "Yay!" : ":(") << endl;
}
