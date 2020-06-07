#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 1e9;

int main() {
  ll a, r, n;
  cin >> a >> r >> n;
  if (r == 1) {
    cout << a << endl;
    return 0;
  }

  if (n > 32) a = MAX + 1;
  while (a <= MAX && n > 1) {
    a *= r;
    n--;
  }

  if (a > MAX) {
    cout << "large" << endl;
  } else {
    cout << a << endl;
  }
}
