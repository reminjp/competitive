#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  vector<ll> p{0, 1};
  for (ll i = 2; p[p.size() - 1] - p[p.size() - 2] < x; i++) {
    p.push_back(i * i * i * i * i);
  }

  bool r = false;
  ll a, b;
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < p.size(); j++) {
      for (auto s : {-1, 1}) {
        if (p[i] - s * p[j] == x) {
          a = i;
          b = s * j;
        }
      }
    }
  }
  cout << a << ' ' << b << endl;
}
