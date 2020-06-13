#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  cout << (v > w && t * (v - w) >= abs(a - b) ? "YES" : "NO") << endl;
}
