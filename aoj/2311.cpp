#include <bits/stdc++.h>
using namespace std;

const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  vector<string> s(8);
  for (auto& e : s) {
    cin >> e;
  }
  string piece = "ox";
  for (int turn = false, passed = 0; passed < 2; turn ^= true) {
    vector<pair<int, int>> v{{-1, -1}};
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (s[i][j] == '.') {
          vector<pair<int, int>> u{{i, j}};
          for (int k = 0; k < 8; k++) {
            vector<pair<int, int>> line;
            for (int l = 1;; l++) {
              int y = i + l * dy[k], x = j + l * dx[k];
              if (0 <= y && y < 8 && 0 <= x && x < 8 && s[y][x] != '.') {
                line.push_back({y, x});
              } else {
                break;
              }
            }
            auto e = find_if(begin(line), end(line), [&](auto x) { return s[x.first][x.second] == piece[turn]; });
            if (e != end(line)) {
              for (auto it = begin(line); it != e; it++) {
                u.push_back(*it);
              }
            }
          }
          if (!turn && u.size() > v.size() || turn && u.size() >= v.size()) {
            v = u;
          }
        }
      }
    }
    if (v.size() > 1) {
      for (auto e : v) {
        s[e.first][e.second] = piece[turn];
      }
      passed = 0;
    } else {
      passed++;
    }
  }
  for (auto e : s) {
    cout << e << endl;
  }
  return 0;
}
