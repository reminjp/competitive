#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
const string S = "atcoder";

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int r = INF, a = 0;
    for (int i = 0; i < S.size() + 1; i++) {
      int l = INF, e = INF;
      for (int j = i; j < s.size(); j++) {
        if (s[j] > S[i]) l = min(l, j - i);
        if (s[j] == S[i]) e = min(e, j - i);
      }
      r = min(r, a + l);
      if (e == INF) break;
      a += e;
    }
    cout << (r == INF ? -1 : r) << endl;
  }
}
