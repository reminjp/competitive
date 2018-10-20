#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<map<int, int>> m(2, map<int, int>());
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    m[i % 2][e]++;
  }
  vector<vector<pair<int, int>>> v(2, vector<pair<int, int>>());
  for (int i = 0; i < 2; i++) {
    v[i].push_back({0, 0});
    for (auto e : m[i]) {
      v[i].push_back({-e.second, e.first});
    }
    sort(begin(v[i]), end(v[i]));
  }
  int d = v[0][0].second == v[1][0].second ? min(v[0][0].first + v[1][1].first, v[0][1].first + v[1][0].first)
                                           : v[0][0].first + v[1][0].first;
  cout << n + d << endl;
}
