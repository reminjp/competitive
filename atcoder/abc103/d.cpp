#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (auto &e : a) {
    cin >> e.first >> e.second;
  }
  sort(begin(a), end(a));

  vector<int> v;
  for (auto e : a) {
    if (v.empty() || v.back() <= e.first) {
      v.push_back(e.second);
    } else {
      *rbegin(v) = min(v.back(), e.second);
    }
  }
  cout << v.size() << endl;
}
