#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<bool> r(n, true);
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    int answer = -1;
    if (d) {
      vector<int> a(d);
      for (auto& e : a) {
        cin >> e;
        p[e]++;
      }
      sort(begin(a), end(a), [p](int a, int b) { return p[a] < p[b]; });
      for (auto e : a) {
        if (r[e]) {
          answer = e;
          r[e] = false;
          break;
        }
      }
    }
    cout << answer << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
