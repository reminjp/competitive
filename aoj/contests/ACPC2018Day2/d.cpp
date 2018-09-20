#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
  int h, w, ai, aj, bi, bj;
  cin >> h >> w >> ai >> aj >> bi >> bj;
  vector<vector<pair<ll, ll>>> r(h, vector<pair<ll, ll>>(w, {1e9, 0}));
  queue<pair<int, int>> q;
  q.push({ai, aj});
  r[ai][aj] = {0, 1};
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    vector<pair<int, int>> v = {{p.first, p.second + 1},
                                {p.first + 1, p.second},
                                {p.first, p.second - 1},
                                {p.first - 1, p.second},
                                {p.first, 0},
                                {p.first, w - 1},
                                {0, p.second},
                                {h - 1, p.second}};
    for (auto e : v) {
      if (e == p || e.first < 0 || h <= e.first || e.second < 0 || w <= e.second) {
        continue;
      }
      if (r[p.first][p.second].first + 1 == r[e.first][e.second].first) {
        r[e.first][e.second].second += r[p.first][p.second].second;
        r[e.first][e.second].second %= mod;
      } else if (r[p.first][p.second].first + 1 < r[e.first][e.second].first) {
        r[e.first][e.second].first = r[p.first][p.second].first + 1;
        r[e.first][e.second].second = r[p.first][p.second].second;
        q.push(e);
      }
    }
  }
  cout << r[bi][bj].first << " " << r[bi][bj].second << endl;
}
