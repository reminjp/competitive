#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  set<ll> v;
  for (int i = 0; i < 100000; i++) {
    int s = 0;
    for (int j = 1; j <= i; j *= 10) {
      s += i % (10 * j) / j;
    }

    for (int j = 0; j <= 13; j++) {
      ll d = 1;
      for (int k = 0; k < j; k++) {
        d *= 10;
      }
      // ((i + 1) * d - 1) / (s + 9 * j) <= ((i + 2) * d - 1) / (s + 9 * j + 1)
      if (((i + 1) * d - 1) * (s + 9 * j + 1) <= ((i + 2) * d - 1) * (s + 9 * j)) {
        v.insert((i + 1) * d - 1);
      }
    }
  }
  v.erase(0);

  int k;
  cin >> k;
  auto it = begin(v);
  for (int i = 0; i < k; i++, it++) {
    cout << *it << endl;
  }
}
