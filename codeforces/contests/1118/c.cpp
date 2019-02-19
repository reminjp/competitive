#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n * n; i++) {
    int e;
    cin >> e;
    m[e]++;
  }

  int n1 = 0, n2 = 0, n4 = n * n;
  if (n % 2) {
    n1 = 1;
    n2 = 2 * (n - 1);
    n4 = n * n - n1 - n2;
  }
  bool r = true;
  vector<vector<int>> t(n, vector<int>(n));
  int p2 = 0, p4 = 0;
  for (auto e : m) {
    while (e.second) {
      if (n4 && e.second >= 4) {
        int y = p4 / (n / 2), x = p4 % (n / 2);
        t[y][x] = t[n - 1 - y][x] = t[y][n - 1 - x] = t[n - 1 - y][n - 1 - x] = e.first;
        e.second -= 4;
        n4 -= 4;
        p4++;
      } else if (n2 && e.second >= 2) {
        if (p2 < n / 2) {
          t[p2][n / 2] = t[n - 1 - p2][n / 2] = e.first;
        } else {
          t[n / 2][p2 - n / 2] = t[n / 2][n - 1 - (p2 - n / 2)] = e.first;
        }
        e.second -= 2;
        n2 -= 2;
        p2++;
      } else if (n1) {
        t[n / 2][n / 2] = e.first;
        e.second -= 1;
        n1 -= 1;
      } else {
        r = false;
        break;
      }
    }
    if (!r) break;
  }

  cout << (r ? "YES" : "NO") << endl;
  if (r) {
    for (const auto& e : t) {
      for (auto ee : e) {
        cout << ee << " ";
      }
      cout << endl;
    }
  }
}
