#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  for (; q > 0; q--) {
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int> l(2);
    for (int i = 0; i < s.size(); i++) {
      for (int j = s[i].size() - 1; j >= 0; j--) {
        if (s[i][j] == '1') {
          l[i] = j;
          break;
        }
      }
    }
    int r = l[0];
    for (int i = 0; i < s[0].size(); i++) {
      if (s[0][i] != s[1][i]) {
        r = i;
        break;
      }
    }
    int m = 0;
    for (int i = 0; i < s.size(); i++) {
      m += abs(l[i] - r);
    }
    cout << m << endl;
  }
}
