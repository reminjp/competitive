#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> s(n + 1), p(n + 1);
  s[0] = p[0] = 1;
  for (int i = 1; i <= n; i++) {
    s[i] = 2 * s[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }
  ll r = 0;
  while (x > 0) {
    if (x >= s[n]) {
      r += p[n];
      x -= s[n];
      if (x > 0) {
        r++;
        x--;
      }
    } else if (x < s[n]) {
      n--;
      x--;
    }
  }
  cout << r << endl;
}
