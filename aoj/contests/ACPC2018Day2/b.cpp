#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(ll a2, ll a1, ll b2, ll b1, bool t) {
  if (!a2 && !a1 || !b2 && !b1) {
    return -1;
  }
  ll k = a2 + a1;
  if (t) {
    if (k < 2 * b2) {
      return 1 + f(b2 - (k + 1) / 2, b1 + k % 2, a2, a1, !t);
    } else {
      k -= 2 * b2;
      return 1 + f(0, max((ll)0, b1 - k), a2, a1, !t);
    }
  } else {
    if (k < b2) {
      return 1 + f(b2 - k, b1 + k, a2, a1, !t);
    } else {
      k -= b2;
      return 1 + f(0, max((ll)0, b2 + b1 - k), a2, a1, !t);
    }
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << min(f(a, 0, b, 0, false), f(a, 0, b, 0, true)) << endl;
}
