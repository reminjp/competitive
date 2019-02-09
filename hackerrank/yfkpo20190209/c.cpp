#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n;
  cin >> n;
  vector<int> s(n), t(n);
  for (auto &e : s) {
    cin >> e;
  }
  for (auto &e : t) {
    cin >> e;
  }
  vector<pair<int, int>> r(n);
  r[0] = {1, 1};
  for (int i = 1; i < n; i++) {
    int x = s[i] - t[i], y = s[0];
    int d = gcd(x, y);
    x /= d;
    y /= d;
    r[i] = {x, y};
  }
  for (auto e : r) {
    cout << e.first << " " << e.second << endl;
  }
}
