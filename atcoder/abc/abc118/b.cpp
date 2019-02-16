#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      v[a - 1]++;
    }
  }
  int r = 0;
  for (auto e : v) {
    r += e == n;
  }
  cout << r << endl;
}
