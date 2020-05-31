#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
using int128 = __int128_t;
constexpr int64 MAX = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int64> a(n);
  bool zero = false;
  for (auto &e : a) {
    cin >> e;
    if (e == 0) zero = true;
  }

  if (zero) {
    cout << 0 << endl;
    return 0;
  }

  bool valid = true;
  int128 r = 1;
  for (auto e : a) {
    valid = valid && r * e <= MAX;
    r *= e;
  }
  cout << (valid ? (int64)r : -1) << endl;
}
