#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  int r = 0;
  vector<vector<int>> v{vector<int>(a1), vector<int>(a2), vector<int>(a3)};
  vector<int> p(a1 + a2 + a3);
  iota(p.begin(), p.end(), 1);
  do {
    copy(p.begin(), p.begin() + a1, v[0].begin());
    copy(p.begin() + a1, p.begin() + a1 + a2, v[1].begin());
    copy(p.begin() + a1 + a2, p.begin() + a1 + a2 + a3, v[2].begin());
    bool valid = true;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (i - 1 >= 0) valid = valid && v[i - 1][j] < v[i][j];
        if (j - 1 >= 0) valid = valid && v[i][j - 1] < v[i][j];
      }
    }
    if (valid) r++;
  } while (next_permutation(p.begin(), p.end()));
  cout << r << endl;
}
