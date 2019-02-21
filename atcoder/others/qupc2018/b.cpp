#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int q;
  cin >> q;
  for (; q > 0; q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll s = 100 * a + 10 * b + c;
    bool r = false;
    if (s % 2 == 0) {
      s /= 2;
      s -= 100 * min(a, s / 100);
      s -= 10 * min(b, s / 10);
      s -= min(c, s);
      r = s == 0;
    }
    cout << (r ? "Yes" : "No") << endl;
  }
}
