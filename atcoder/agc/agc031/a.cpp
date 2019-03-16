#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<ll> c(26);
  for (auto e : s) {
    c[e - 'a']++;
  }
  ll r = 1;
  for (auto e : c) {
    r = (r * (e + 1)) % mod;
  }
  r -= 1;
  cout << r << endl;
}
