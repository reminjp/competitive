#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  int r = 1e9;
  for (int b = 0; b < (1 << h - 1); b++) {
    int rb = bitset<9>(b).count();
    vector<int> m(h);
    for (int i = 1; i < h; i++) m[i] = m[i - 1] + ((b >> i - 1) & 1);

    bool valid = true;
    vector<int> c(h);
    for (int j = 0; j < w && valid; j++) {
      bool should_cut = false;
      for (int i = 0; i < h; i++) {
        c[m[i]] += s[i][j] == '1';
        should_cut = should_cut || c[m[i]] > k;
      }
      if (should_cut) {
        rb++;
        for (auto& e : c) e = 0;
        for (int i = 0; i < h; i++) {
          c[m[i]] += s[i][j] == '1';
          valid = valid && c[m[i]] <= k;
        }
      }
    }
    if (valid) r = min(r, rb);
  }
  cout << r << endl;
}
