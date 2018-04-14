#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> w(n), h(n);
  int q = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> h[i];
    q += 2 * w[i] + 2 * h[i];
  }
  vector<pair<double, double>> s;
  s.push_back(make_pair(q, q));
  for (int i = 0; i < n; i++) {
    double a = 2 * min(w[i], h[i]), b = 2 * sqrt(w[i] * w[i] + h[i] * h[i]);
    vector<pair<double, double>> t;
    for (auto e : s) {
      t.push_back(e);
      t.push_back(make_pair(e.first + a, e.second + b));
    }
    sort(begin(t), end(t));
    s.clear();
    for (int i = 0; i < t.size(); i++) {
      if (i < t.size() - 1 && t[i].second >= t[i + 1].first) {
        t[i + 1].first = t[i].first;
      } else {
        s.push_back(t[i]);
      }
    }
  }
  double m = 0.0;
  for (auto e : s) {
    if (e.first <= p && p <= e.second) {
      m = p;
    } else if (e.second <= p) {
      m = e.second;
    }
  }
  cout << fixed << setprecision(6);
  cout << m << endl;
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
