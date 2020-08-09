#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int A_MAX = 10;
constexpr int Q = 200000;

int main() {
  int n;
  cin >> n;
  vector<tuple<char, int, int, int>> r(n);
  for (auto& e : r) cin >> get<0>(e) >> get<1>(e) >> get<2>(e) >> get<3>(e);

  int ac = 0, wa = 0;
  for (int a = 0; a <= A_MAX; a++) {
    for (int b = 0; b <= A_MAX; b++) {
      vector<int> v(Q);

      v[0] = a;
      v[1] = b;

      for (auto [o, i, j, k] : r) {
        if (o == '+') {
          v[k] = v[i] + v[j];
        } else {
          v[k] = v[i] < v[j] ? 1 : 0;
        }

        // cerr << o << ' ' << i << ' ' << j << ' ' << k << endl;
        // for (auto e : v) cerr << e << ' ';
        // cerr << endl;
      }

      (a * b == v[2] ? ac : wa)++;
    }
  }
  cout << "ac: " << ac << "\nwa: " << wa << endl;
}
