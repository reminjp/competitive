#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  while (cin >> h >> w, h) {
    vector<vector<int>> a(h, vector<int>(w));
    for (auto& ai : a) {
      for (auto& e : ai) {
        cin >> e;
      }
    }
    int r = 0;
    for (int y1 = 0; y1 < h; y1++) {
      for (int y2 = y1 + 3; y2 <= h; y2++) {
        for (int x1 = 0; x1 < w; x1++) {
          for (int x2 = x1 + 3; x2 <= w; x2++) {
            int outer_min = 1e9, inner_max = 0, inner_sum = 0;
            for (int i = y1; i < y2; i++) {
              outer_min = min(outer_min, min(a[i][x1], a[i][x2 - 1]));
            }
            for (int j = x1; j < x2; j++) {
              outer_min = min(outer_min, min(a[y1][j], a[y2 - 1][j]));
            }
            for (int i = y1 + 1; i < y2 - 1; i++) {
              for (int j = x1 + 1; j < x2 - 1; j++) {
                inner_max = max(inner_max, a[i][j]);
                inner_sum += a[i][j];
              }
            }
            if (inner_max < outer_min) {
              r = max(r, (y2 - y1 - 2) * (x2 - x1 - 2) * outer_min - inner_sum);
            }
          }
        }
      }
    }
    cout << r << endl;
  }
}
