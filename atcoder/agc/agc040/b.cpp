#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int width(P a) { return max(0, a.second - a.first); }
P unite(P a, P b) { return make_pair(max(a.first, b.first), min(a.second, b.second)); }

int main() {
  int n;
  cin >> n;
  vector<P> v(n);
  for (auto& e : v) {
    cin >> e.first >> e.second;
    e.second++;
  }
  sort(v.begin(), v.end());

  vector<P> s{v[0], v[1]};
  for (int i = 2; i < n; i++) {
    vector<pair<int, vector<P>>> t{
        {width(unite(s[0], v[i])) + width(s[1]), {unite(s[0], v[i]), s[1]}},
        {width(s[0]) + width(unite(s[1], v[i])), {s[0], unite(s[1], v[i])}},
        {width(unite(s[0], s[1])) + width(v[i]), {unite(s[0], s[1]), v[i]}},
    };
    s = max_element(t.rbegin(), t.rend())->second;
  }
  cout << width(s[0]) + width(s[1]) << endl;
}
