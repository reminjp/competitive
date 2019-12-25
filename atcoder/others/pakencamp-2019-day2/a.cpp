#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }
  vector<pair<int, int>> r(q);
  for (auto& e : r) cin >> e.first >> e.second;

  vector<vector<int>> s(n, vector<int>(n));
  int highest_score = 0;
  for (int k1 = 1; k1 <= k; k1++) {
    for (int k2 = 1; k2 <= k; k2++) {
      vector<vector<int>> t(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        vector<int> v1(n), v2(n);
        for (int j = 0; j < n; j++) {
          v1[j] = a[i][j] == k1;
          v2[j] = a[i][j] == k2;
        }
        for (int j = 0; j + 1 < n; j++) v1[j + 1] += v1[j];
        for (int j = n - 1; j >= 1; j--) v2[j - 1] += v2[j];
        int highest_j = 0;
        for (int j = 0; j + 1 < n; j++) {
          if (v1[j] + v2[j + 1] > v1[highest_j] + v2[highest_j + 1]) highest_j = j;
        }
        fill(t[i].begin(), t[i].begin() + highest_j + 1, k1);
        fill(t[i].begin() + highest_j + 1, t[i].end(), k2);
      }

      int score = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) score += t[i][j] == a[i][j];
      }
      if (score > highest_score) {
        highest_score = score;
        s = t;
      }
    }
  }
  cerr << "score " << highest_score << endl;

  for (const auto& v : s) {
    for (const auto& e : v) cout << e << ' ';
    cout << endl;
  }
}
