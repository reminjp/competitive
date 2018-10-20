#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
};

int main() {
  int n;
  cin >> n;
  vector<point> p(n);
  for (auto &e : p) cin >> e.x >> e.y;

  bool is_small_case = true;
  for (auto e : p) is_small_case &= -10 <= e.x && e.x <= 10 && -10 <= e.y && e.y <= 10;
  if (!is_small_case) return 1;

  bool is_possible = true;
  for (auto e : p) is_possible &= abs(p.front().x + p.front().y) % 2 == abs(e.x + e.y) % 2;
  if (!is_possible) {
    cout << -1 << endl;
    return 0;
  }

  int m = 20 - (p.front().x + p.front().y) % 2;
  vector<int> d(m, 1);
  vector<string> w(n);
  for (int i = 0; i < n; i++) {
    auto e = p[i];
    w[i] += string(abs(e.x), e.x < 0 ? 'L' : 'R');
    w[i] += string(abs(e.y), e.y < 0 ? 'D' : 'U');
    while (w[i].size() < m) w[i] += "LR";
  }

  cout << m << endl;
  for (auto e : d) cout << e << " ";
  cout << endl;
  for (auto e : w) cout << e << endl;
}
