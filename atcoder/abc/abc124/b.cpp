#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &e : h) cin >> e;
  int r = 0, m = 0;
  for (auto e : h) {
    if (m <= e) {
      m = e;
      r++;
    }
  }
  cout << r << endl;
}
