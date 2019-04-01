#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  a.push_back(0);
  ll s = 0;
  int k = 0;
  for (auto e : a) {
    if (e % 2) {
      s += e;
      k++;
    } else {
      if (k >= m) cout << s << endl;
      s = 0;
      k = 0;
    }
  }
}
