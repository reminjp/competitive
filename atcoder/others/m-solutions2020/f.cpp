#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<char> u(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> u[i];

  map<int, vector<int>> mu, mr, md, ml, mu_s, mu_d, mr_s, mr_d, md_s, md_d, ml_s, ml_d;
  for (int i = 0; i < n; i++) {
    switch (u[i]) {
      case 'U': {
        mu[x[i]].push_back(y[i]);
        mu_s[x[i] + y[i]].push_back(x[i]);
        mu_d[x[i] - y[i]].push_back(x[i]);
        break;
      }
      case 'R': {
        mr[y[i]].push_back(x[i]);
        mr_s[x[i] + y[i]].push_back(x[i]);
        mr_d[x[i] - y[i]].push_back(x[i]);
        break;
      }
      case 'D': {
        md[x[i]].push_back(y[i]);
        md_s[x[i] + y[i]].push_back(x[i]);
        md_d[x[i] - y[i]].push_back(x[i]);
        break;
      }
      case 'L': {
        ml[y[i]].push_back(x[i]);
        ml_s[x[i] + y[i]].push_back(x[i]);
        ml_d[x[i] - y[i]].push_back(x[i]);
        break;
      }
    }
  }

  int r = INF;

  auto f = [&](map<int, vector<int>>& m1, map<int, vector<int>> m2, int s) {
    for (auto& [e, v1] : m1) {
      if (!m2.count(e)) continue;
      auto& v2 = m2[e];
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      for (auto e1 : v1) {
        auto it = lower_bound(v2.begin(), v2.end(), e1);
        if (it == v2.end()) continue;
        r = min(r, s * (*it - e1));
      }
    }
  };

  f(mu, md, 5);       // ^ and v
  f(mr, ml, 5);       // > and <
  f(mr_s, mu_s, 10);  // > and ^
  f(mr_d, md_d, 10);  // > and v
  f(mu_d, ml_d, 10);  // ^ and <
  f(md_s, ml_s, 10);  // v and <

  if (r == INF) {
    cout << "SAFE" << endl;
  } else {
    cout << r << endl;
  }
}
