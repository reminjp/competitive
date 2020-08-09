#include <bits/stdc++.h>
using namespace std;
constexpr int A_MAX = 10;

constexpr int A = 0, B = 1, P = 2;
constexpr int ONE = 3;
constexpr int VA = ONE + 2;
constexpr int VB = VA + A_MAX + 1;
constexpr int T = VB + A_MAX + 1;

int main() {
  vector<tuple<char, int, int, int>> r;

  r.push_back({'+', A, B, ONE + 1});
  r.push_back({'<', ONE, ONE + 1, ONE});

  for (int i = 0; i < A_MAX; i++) {
    r.push_back({'<', VA, A, VA + 1 + i});
    r.push_back({'+', VA, ONE, VA});
  }
  for (int i = 0; i < A_MAX; i++) {
    r.push_back({'<', VB, B, VB + 1 + i});
    r.push_back({'+', VB, ONE, VB});
  }

  for (int i = 0; i < A_MAX; i++) {
    for (int j = 0; j < A_MAX; j++) {
      r.push_back({'<', VA + 1 + i, ONE, T + 1});
      r.push_back({'<', VB + 1 + j, ONE, T + 2});
      r.push_back({'<', ONE, ONE, T});
      r.push_back({'+', T + 1, T + 2, T});
      r.push_back({'<', T, ONE, T});
      r.push_back({'+', P, T, P});
    }
  }

  cout << r.size() << endl;
  for (auto e : r) {
    cout << get<0>(e) << ' ';
    cout << get<1>(e) << ' ';
    cout << get<2>(e) << ' ';
    cout << get<3>(e) << '\n';
  }
  cout << flush;
}
