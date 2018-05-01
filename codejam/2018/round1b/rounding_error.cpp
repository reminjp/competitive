#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> a(l);
  int s = 0;
  for (auto& e : a) {
    cin >> e;
    s += e;
  }
  int p = 0;
  priority_queue<double> r;
  for (auto e : a) {
    double t = 100.0 * e / n;
    p += round(t);
    r.push(t - round(t));
  }
  for (int i = 0; i < n - s; i++) {
    r.push(0);
  }
  for (int i = 0; i < n - s; i++) {
    double e = r.top();
    r.pop();
    e += 100.0 / n;
    p += round(e);
    e -= round(e);
    r.push(e);
  }
  cout << p << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
