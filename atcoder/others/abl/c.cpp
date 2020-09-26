#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  dsu d(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d.merge(a, b);
  }
  cout << d.groups().size() - 1 << endl;
}
