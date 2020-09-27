#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
  const vector<pair<int, int>> D{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int id, N, K;
  cin >> id >> N >> K;
  vector<string> S(N);
  for (auto& e : S) cin >> e;

  dsu d(N * N);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      for (auto [dy, dx] : D) {
        auto y2 = y + dy, x2 = x + dx;
        if (unsigned(y2) >= N || unsigned(x2) >= N) continue;
        if (S[y][x] != S[y2][x2]) continue;
        d.merge(y * N + x, y2 * N + x2);
      }
    }
  }

  vector<tuple<int, int, int>> r;
  while (true) {
    auto groups = d.groups();
    vector<vector<int>> to_group_index(N, vector<int>(N));
    for (int i = 0; i < groups.size(); i++) {
      for (const auto e : groups[i]) to_group_index[e / N][e % N] = i;
    }

    vector<vector<set<int>>> v(groups.size(), vector<set<int>>(K));
    vector<vector<set<int>>> g(groups.size(), vector<set<int>>(K));
    for (int i = 0; i < groups.size(); i++) {
      for (const auto e : groups[i]) {
        auto y = e / N, x = e % N;
        for (auto [dy, dx] : D) {
          auto y2 = y + dy, x2 = x + dx;
          if (unsigned(y2) >= N || unsigned(x2) >= N) continue;
          if (S[y][x] == S[y2][x2]) continue;
          v[i][S[y2][x2] - '1'].insert(y2 * N + x2);
          g[i][S[y2][x2] - '1'].insert(to_group_index[y2][x2]);
        }
      }
    }

    int i_max = 0, k_max = 0;
    for (int i = 0; i < groups.size(); i++) {
      for (int k = 0; k < K; k++) {
        if (g[i][k].size() > g[i_max][k_max].size() ||
            (g[i][k].size() == g[i_max][k_max].size() &&
             v[i][k].size() + groups[i].size() > v[i_max][k_max].size() + groups[i_max].size())) {
          i_max = i;
          k_max = k;
        }
      }
    }
    if (v[i_max][k_max].size() == 0) break;
    {
      auto t = groups[i_max].front();
      r.push_back({t / N, t % N, k_max});
      for (auto e : groups[i_max]) S[e / N][e % N] = k_max + '1';
      for (auto e : v[i_max][k_max]) d.merge(t, e);
    }

    // for (const auto& e : S) cerr << e << endl;
  }

  cout << r.size() << '\n';
  for (const auto [y, x, c] : r) cout << y + 1 << ' ' << x + 1 << ' ' << c + 1 << '\n';
}
