#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  while (m--) {
    int a;
    cin >> a;
    a = -a;
    auto i = upper_bound(v.begin(), v.end(), a) - v.begin();
    cout << (i == n ? -1 : i + 1) << endl;
    if (i < n) v[i] = a;
  }
}
