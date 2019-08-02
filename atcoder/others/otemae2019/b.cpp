#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  vector<int> v(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[x - 1]++;
  }
  int r = 0;
  for (int i = 0; i < m; i++) {
    int t = v[i];
    for (int j = 1; j <= k; j++) {
      t += (0 <= i - j && v[i - j] > 0) || (i + j < m && v[i + j] > 0);
    }
    r = max(r, t);
  }
  cout << r << endl;
}
