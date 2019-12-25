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
  for (auto& e : r) {
    cin >> e.first >> e.second;
    e.first--;
    e.second--;
  }
  sort(r.begin(), r.end());

  vector<vector<int>> s(n, vector<int>(n, 4));
  for (int i = 0; i <= r.front().first; i++) fill(s[i].begin(), s[i].begin() + r.front().second + 1, 1);
  int ci = r.front().first, cj = r.front().second;
  for (auto e : r) {
    if (e.first < ci + k && e.second != cj) continue;
    if (cj < e.second) {
      for (int i = ci + 1; i < e.first; i++) fill(s[i].begin(), s[i].begin() + cj + 1, 1);
      fill(s[e.first].begin(), s[e.first].begin() + e.second + 1, 1);
    } else {
      for (int i = ci + 1; i <= e.first; i++) fill(s[i].begin(), s[i].begin() + e.second + 1, 1);
    }
    ci = e.first;
    cj = e.second;
  }
  for (int i = ci + 1; i < n; i++) fill(s[i].begin(), s[i].begin() + cj + 1, 1);
  for (int c = 1; c <= 2; c++) {
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        if (s[i][j] != k) continue;
        bool b = s[i][j - 1] == c;
        if (i - 1 >= 0) b = b || s[i - 1][j - 1] == c || s[i - 1][j] == c;
        if (i + 1 < n) b = b || s[i + 1][j - 1] == c || s[i + 1][j] == c;
        if (b) s[i][j] = c + 1;
      }
    }
  }

  vector<vector<int>> s_highest;
  int score_highest = 0;
  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  do {
    vector<vector<int>> t(n, vector<int>(n, 4));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) t[i][j] = p[s[i][j] - 1] + 1;
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) score += t[i][j] == a[i][j];
    }
    if (score > score_highest) {
      score_highest = score;
      s_highest = t;
    }
  } while (next_permutation(p.begin(), p.end()));

  for (const auto& v : s_highest) {
    for (const auto& e : v) cout << e << ' ';
    cout << endl;
  }
}
