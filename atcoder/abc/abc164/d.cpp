#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int K = 2019;

int main() {
  string s;
  cin >> s;

  ll r = 0;
  vector<ll> v(K);
  for (auto e : s) {
    vector<ll> u(K);
    int d = e - '0';
    u[d] += 1;
    for (int i = 0; i < K; i++) {
      u[(10 * i + d) % K] += v[i];
    }
    r += u[0];
    v = u;
  }
  cout << r << endl;
}
