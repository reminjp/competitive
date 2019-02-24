#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3), l(n);
  for (auto& e : a) cin >> e;
  for (auto& e : l) cin >> e;
  int r = 1e9;
  vector<int> b(3);
  for (b[0] = 1; b[0] < (1 << n); b[0]++) {
    for (b[1] = 1; b[1] < (1 << n); b[1]++) {
      if (b[0] & b[1]) continue;
      for (b[2] = 1; b[2] < (1 << n); b[2]++) {
        if ((b[0] & b[2]) || (b[1] & b[2])) continue;
        int rt = 0;
        for (int i = 0; i < 3; i++) {
          int s = 0;
          for (int j = 0; j < n; j++) {
            if (b[i] & (1 << j)) {
              if (s) rt += 10;
              s += l[j];
            }
          }
          rt += abs(a[i] - s);
        }
        r = min(r, rt);
      }
    }
  }
  cout << r << endl;
}
