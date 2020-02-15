#include <bits/stdc++.h>
using namespace std;

struct Monomino {
  int c, v;
};

int calculate_line_score(int K, const vector<Monomino>& monominos, const vector<int>& line) {
  vector<int> s(K);
  for (auto e : line) s[monominos[e].c] += monominos[e].v;
  return *max_element(s.begin(), s.end());
}

int main() {
  int N, W, K, V;
  cin >> N >> W >> K >> V;
  vector<Monomino> monominos(N);
  for (auto& e : monominos) cin >> e.c >> e.v;

  vector<int> r(N);
  int h = (N - 1) / W + 1;
  vector<vector<int>> lines(h);
  vector<int> heights(W);

  for (int i = 0; i < N; i++) {
    int x_max = 0, y_max = h, s_max = 0;
    for (int x = 0; x < W; x++) {
      int y = heights[x];
      if (y >= h) continue;
      int s = -calculate_line_score(K, monominos, lines[y]);
      lines[y].push_back(i);
      s += calculate_line_score(K, monominos, lines[y]);
      lines[y].pop_back();
      if (s > s_max || (s == s_max && y < y_max)) {
        x_max = x;
        y_max = y;
        s_max = s;
      }
    }
    lines[heights[x_max]].push_back(i);
    heights[x_max]++;
    r[i] = x_max;
  }

  for (auto e : r) cout << e << '\n';
  cout << flush;
}
