#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  vector<int> r;
  while (!a.empty()) {
    bool b = true;
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i] == i + 1) {
        a.erase(begin(a) + i);
        r.push_back(i + 1);
        b = false;
        break;
      }
    }
    if (b) break;
  }
  if (r.size() == n) {
    reverse(begin(r), end(r));
    for (auto e : r) {
      cout << e << endl;
    }
  } else {
    cout << -1 << endl;
  }
}
