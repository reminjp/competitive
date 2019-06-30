#include <bits/stdc++.h>
using namespace std;

// constexpr int TIME_LIMIT = 30 * 1000;

class pseudo_boolean_function {
 public:
  int n;
  vector<pair<int, vector<int>>> v;

  void push(int c, const vector<int>& v) { this->v.push_back({c, v}); }
  void clear() {
    this->n = 0;
    this->v.clear();
  }
  int operator()(const vector<bool>& x) {
    assert(x.size() >= n);
    int r = 0;
    for (const auto& t : this->v) {
      bool b = true;
      for (const auto& e : t.second) {
        assert(e < n);
        b &= x[e];
      }
      if (b) r += t.first;
    }
    return r;
  }
};

ostream& operator<<(ostream& os, const pseudo_boolean_function& f) {
  os << f.n << ' ' << f.v.size();
  for (const auto& t : f.v) {
    cout << '\n' << t.second.size() << ' ' << t.first;
    for (const auto& e : t.second) cout << ' ' << e + 1;
  }
  return os;
}

istream& operator>>(istream& is, pseudo_boolean_function& f) {
  int k;
  is >> f.n >> k;
  f.v = vector<pair<int, vector<int>>>(k);
  for (auto& t : f.v) {
    int d;
    cin >> d >> t.first;
    t.second = vector<int>(d);
    for (auto& e : t.second) {
      cin >> e;
      e--;
    }
  }
  return is;
}

int main() {
  pseudo_boolean_function f;
  cin >> f;

  pseudo_boolean_function g;
  int ng = 0, ok = 5 * (3000 - f.n) + (1 + f.n + f.n * (f.n - 1) / 2);
  while (ng + 1 < ok) {
    int max_coeff = (ng + ok) / 2;
    bool is_possible = true;
    // cerr << max_coeff << endl;

    int n = f.n;
    map<vector<int>, int> m;
    for (const auto& t : f.v) {
      int c = t.first;
      vector<int> v = t.second;
      if (c > max_coeff && v.size()) {
        is_possible = false;
        break;
      }

      // if (v.size() > 2) {
      //   if (-3 < c && c < 0) {
      //     continue;
      //   } else if (0 < c && c < 3) {
      //     m[{}] += c;
      //   }
      // }

      if (v.size() <= 2) {
        m[v] += c;
      } else if (c < 0) {
        int k = max_coeff / abs(c) + 1;
        if (k < 3) {
          is_possible = false;
          break;
        }
        queue<vector<int>> q;
        q.push(v);
        while (!q.empty()) {
          auto fr = q.front();
          q.pop();
          if (fr.size() < 3) {
            m[fr] += c;
          } else {
            vector<vector<int>> vn(min(k, (int)fr.size()));
            for (int i = 0; i < fr.size(); i++) {
              vn[i % vn.size()].push_back(fr[i]);
            }
            int w = n;
            n++;
            m[vector<int>{w}] += (vn.size() - 1) * -c;
            for (auto& e : vn) {
              e.push_back(w);
              q.push(e);
            }
          }
        }
      } else {
        for (int i = 0; i < v.size(); i += 2) {
          m[vector<int>{v[i], v[i + 1]}] += c;
          if (i + 2 < v.size()) {
            int w = n;
            n++;
            m[vector<int>{w}] += c;
            m[vector<int>{v[i], w}] += -c;
            m[vector<int>{v[i + 1], w}] += -c;
            v.push_back(w);
          }
        }
      }

      if (5 * (n - f.n) + m.size() > max_coeff) {
        is_possible = false;
        break;
      }
    }

    for (const auto& e : m) {
      if (e.first.size() > 0 && e.second > max_coeff) {
        is_possible = false;
        break;
      }
    }

    if (is_possible) {
      ok = max_coeff;
      g.clear();
      g.n = n;
      for (const auto& e : m) {
        if (e.second) {
          g.push(e.second, e.first);
        }
      }
    } else {
      ng = max_coeff;
    }
  }

  // for (auto& t : vp) {
  //   while (t.second.size() > 2) {
  //     int w = n;
  //     n++;
  //     m[{min(t.second[0], t.second[1]), max(t.second[0], t.second[1])}] += t.first;
  //     m[{w, w}] += t.first;
  //     m[{min(t.second[0], w), max(t.second[0], w)}] += -t.first;
  //     m[{min(t.second[1], w), max(t.second[1], w)}] += -t.first;
  //     t.second = vector<int>(begin(t.second) + 2, end(t.second));
  //     t.second.push_back(w);
  //   }
  //   m[{min(t.second[0], t.second[1]), max(t.second[0], t.second[1])}] += t.first;
  // }
  // for (const auto& t : vn) {
  //   int w = n;
  //   n++;
  //   m[{w, w}] += ((int)t.second.size() - 1) * -t.first;
  //   for (const auto& e : t.second) m[{min(e, w), max(e, w)}] += t.first;
  // }

  cout << g << endl;

  assert(f.n <= g.n && g.n <= 3000);
  assert(1 <= g.v.size() && g.v.size() <= 1 + g.n + g.n * (g.n - 1) / 2);
  for (const auto& t : g.v) {
    assert(1 <= abs(t.first) && abs(t.first) < (1ll << 31));
    assert(t.second.size() <= 2);
    for (const auto& e : t.second) {
      assert(1 - 1 <= e && e <= g.n - 1);
    }
  }
}
