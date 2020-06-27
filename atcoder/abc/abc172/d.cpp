#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  ll r = 0;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) v[j]++;
    r += i * v[i];
  }
  cout << r << endl;
}
