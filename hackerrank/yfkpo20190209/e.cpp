#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2) <= pow(d, 2)) {
        v[i].push_back(j);
        v[j].push_back(i);
      }
    }
  }

  vector<bool> u(n);
  stack<vector<int>> s;
  s.push({0});
  while (!s.empty()) {
    auto t = s.top();
    if (t.back() == n - 1) {
      break;
    }
    s.pop();
    for (auto e : v[t.back()]) {
      if (!u[e]) {
        u[e] = true;
        t.push_back(e);
        s.push(t);
        t.pop_back();
      }
    }
  }

  for (auto e : s.top()) {
    cout << e + 1 << endl;
  }
}
