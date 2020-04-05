#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 0; i + 1 < n; i++) a[i + 1] = gcd(a[i], a[i + 1]);
  a.push_back(1);

  while (q--) {
    int s;
    cin >> s;

    int bot = -1, top = n, mid;
    while (bot + 1 < top) {
      mid = bot + (top - bot) / 2;
      int x = gcd(s, a[mid]);
      if (x != 1) {
        bot = mid;
      } else {
        top = mid;
      }
    }
    cout << (top == n ? gcd(s, a[n - 1]) : top + 1) << endl;
  }
}
