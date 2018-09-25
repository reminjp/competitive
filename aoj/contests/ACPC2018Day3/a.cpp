#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> v(4 + 1);
  int r = 0;
  v[4] = s.size();
  for (v[1] = 1; v[1] <= 3; v[1]++) {
    for (v[2] = v[1] + 1; v[2] <= v[1] + 3; v[2]++) {
      for (v[3] = v[2] + 1; v[3] <= v[2] + 3; v[3]++) {
        if (v[4] - v[3] < 1 || 3 < v[4] - v[3]) {
          continue;
        }
        bool is_ok = true;
        for (int i = 0; i < 4; i++) {
          int d = 0;
          for (int j = v[i]; j < v[i + 1]; j++) {
            d = 10 * d + (s[j] - '0');
          }
          is_ok &= d < 256 && !(d ? s[v[i]] == '0' : v[i + 1] - v[i] > 1);
        }
        r += is_ok;
      }
    }
  }
  cout << r << endl;
}
