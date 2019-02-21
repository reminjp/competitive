#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> a(n);
  for (auto &e : a) {
    int x, y;
    cin >> x >> y;
    e = {x + y, {x, y}};
  }
  sort(rbegin(a), rend(a));
  ll r = 0;
  for (int i = 0; i < n; i++) {
    r += i % 2 ? -a[i].second.second : a[i].second.first;
  }
  cout << r << endl;
}
