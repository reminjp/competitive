#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<int> v(n, b);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l - 1; j < r; j++) {
      v[j] = a;
    }
  }
  int s = 0;
  for (auto e : v) {
    s += e;
  }
  cout << s << endl;
}
