#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5;

int main() {
  int n;
  cin >> n;
  vector<string> s(N);
  vector<int> card(n);
  for (auto &e : s) cin >> e;
  for (auto &e : card) cin >> e;

  vector<pair<int, int>> b;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i][j] == 'G') b.push_back({i, j});
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i][j] == 'B') b.push_back({i, j});
    }
  }
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      int d = abs(b[i].first - b[j].first) + abs(b[i].second - b[j].second);
      graph[i].push_back({j, d});
      graph[j].push_back({i, d});
    }
  }
  vector<bool> visited(n + 1);

  function<bool(int, int)> search = [&search, &card, &graph, &visited](int turn, int node) {
    bool win = false;
    visited[node] = true;
    for (auto e : graph[node]) {
      if (!visited[e.first] && e.second == card[turn]) {
        win = win || !search(turn + 1, e.first);
      }
    }
    visited[node] = false;
    return win;
  };
  cout << (search(0, 0) ? "gori" : "uho") << endl;
}
