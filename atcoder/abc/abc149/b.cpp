#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max(0ll, a - k) << ' ' << max(0ll, b - max(0ll, k - a)) << endl;
}
