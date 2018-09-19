#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string d = "DRUL";

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  for (auto &e : c) {
    cin >> e;
  }

  vector<pair<int, int>> v, u;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (c[i][j] == '#') {
        v.push_back({i, j});
      }
    }
  }

  int oy = 0, ox = 0, od = 0;
  bool is_coast = false;
  while (v.size() > 1) {
    int q = (4 + od - 1) % 4;
    cout << "? " << d[q] << endl;
    string a;
    cin >> a;
    if (a[0] == 'Y') {
      for (auto e : v) {
        if (c[e.first + dy[q]][e.second + dx[q]] == '#') {
          e.first += dy[q];
          e.second += dx[q];
          u.push_back(e);
        }
      }
      oy += dy[q];
      ox += dx[q];
      if (is_coast) {
        od = q;
      }
    } else {
      for (auto e : v) {
        if (c[e.first + dy[q]][e.second + dx[q]] != '#') {
          u.push_back(e);
        }
      }
      od = (od + 1) % 4;
      is_coast = true;
    }
    v = u;
    u.clear();
  }

  cout << "! " << v.front().first - oy << " " << v.front().second - ox << endl;
}
