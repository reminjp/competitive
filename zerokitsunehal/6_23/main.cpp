#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void g(ll x, vector<int>& r) {
  while (x) {
    r[x % 10]++;
    x /= 10;
  }
}

void f(ll x, vector<int>& r) {
  for (int i = 2; i * i <= x; i++) {
    int c = 0;
    while (x % i == 0) {
      x /= i;
      c++;
    }
    while (c--) g(i, r);
  }
  if (x > 1) g(x, r);
}

int main() {
  vector<int> v({1, 0, 2, 3, 5, 6, 7, 8, 8, 9});

  do {
    ll d = 0;
    for (auto e : v) d = 10 * d + e;

    vector<int> u(10);
    f(d, u);
    if (*min_element(u.begin(), u.end()) == 1 && *max_element(u.begin(), u.end()) == 1) {
      cout << d << endl;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
}
