#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  for (auto &e : w) {
    cin >> e;
  }
  bool r = true;
  for (int i = 0; i < n - 1; i++) {
    if (w[i].back() != w[i + 1].front()) {
      r = false;
    }
  }
  map<string, int> m;
  for (auto e : w) {
    m[e]++;
    if (m[e] > 1) {
      r = false;
    }
  }
  cout << (r ? "Yes" : "No") << endl;
}
