#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

constexpr int O = 1e5;
constexpr int K = 100;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  mcf_graph<int, int> graph(K + h * w + 2);
  for (int i = 0; i < K; i++) {
    graph.add_edge(0, 2 + i, 1, 0);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      graph.add_edge(2 + K + i * w + j, 1, 1, 0);
    }
  }

  vector<pair<int, int>> v;
  vector<vector<bitset<K>>> b(h, vector<bitset<K>>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      if (s[i][j] == 'o') {
        b[i][j][v.size()] = true;
        v.push_back({i, j});
      }
      if (i - 1 >= 0) b[i][j] |= b[i - 1][j];
      if (j - 1 >= 0) b[i][j] |= b[i][j - 1];

      for (int k = 0; k < v.size(); k++) {
        if (!b[i][j][k]) continue;
        graph.add_edge(2 + k, 2 + K + i * w + j, 1, O - ((i - v[k].first) + (j - v[k].second)));
      }
    }
  }

  auto r = graph.flow(0, 1);
  cout << O * r.first - r.second << endl;
}
