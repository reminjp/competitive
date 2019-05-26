#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].first.second *= -1;
    v[i].second = i + 1;
  }
  sort(begin(v), end(v));
  for (auto e : v) cout << e.second << endl;
}
