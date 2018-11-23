#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int)1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> p(n + 1, 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      p[i] = p[i] * i % mod;
    }
  }
  ll r = 0;
  for (int i = 1; i <= n; i++) {
    int j = n / i;
    r = (r + (mod + p[i] - p[i - 1]) % mod * p[j] % mod) % mod;
  }
  cout << r << endl;
}
