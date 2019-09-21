#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<string> r(h, string(w, '0'));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i < b == j < a) r[i][j] = '1';
    }
  }
  for (const auto& e : r) cout << e << endl;
}
