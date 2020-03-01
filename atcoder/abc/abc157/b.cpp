#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> b(3, vector<bool>(3));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }
  int n;
  cin >> n;
  while (n--) {
    int e;
    cin >> e;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (a[i][j] == e) b[i][j] = true;
      }
    }
  }
  bool r = false;
  for (int i = 0; i < 3; i++) {
    r = r || (b[i][0] && b[i][1] && b[i][2]);
    r = r || (b[0][i] && b[1][i] && b[2][i]);
  }
  r = r || (b[0][0] && b[1][1] && b[2][2]);
  r = r || (b[0][2] && b[1][1] && b[2][0]);
  cout << (r ? "Yes" : "No") << endl;
}
