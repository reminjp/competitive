#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  ll r = 1;
  for (int i = 1; i <= n; i++) {
    r *= i;
    r %= mod;
  }
  cout << r << endl;
}
