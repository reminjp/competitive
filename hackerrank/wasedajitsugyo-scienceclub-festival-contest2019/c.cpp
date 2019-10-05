#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  pair<int, int> p1, p2;
  for (; q > 0; q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int a;
      cin >> a;
      if (a > p1.first) {
        p2 = p1;
        p1 = make_pair(a, 1);
      } else if (a == p1.first) {
        p1.second++;
      } else if (a > p2.first) {
        p2 = make_pair(a, 1);
      } else if (a == p2.first) {
        p2.second++;
      }
    } else if (c == 2) {
      if (p2.second > 0) {
        cout << (long long)p2.first * p2.second << '\n';
      }
    }
  }

  cout << flush;
}
