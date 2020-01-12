#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), w(n);
  for (int i = 0; i < m; i++) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (!a[p]) {
      if (s == "AC") {
        a[p] = 1;
      } else {
        w[p]++;
      }
    }
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i]) continue;
    x += 1;
    y += w[i];
  }
  cout << x << ' ' << y << endl;
}
