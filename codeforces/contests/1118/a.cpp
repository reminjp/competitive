#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int q;
  cin >> q;
  for (; q > 0; q--) {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << (2 * a < b ? n * a : n % 2 * a + n / 2 * b) << endl;
  }
}
