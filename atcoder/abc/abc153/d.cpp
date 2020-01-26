#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll h) { return h <= 1 ? 1 : 1 + 2 * f(h / 2); }

int main() {
  ll h;
  cin >> h;
  cout << f(h) << endl;
}
