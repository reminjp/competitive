#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> a(n + 2), b(n + 2);
  a[n + 1] = b[n + 1] = l + 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];

  auto a2 = a;
  for (int i = 0; i < a2.size(); i++) a2[i] -= i;

  long long r = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] < a[i]) {
      // <-
      if (b[i - 1] + 1 == b[i]) {
        r++;
      } else {
        int j = (upper_bound(a2.begin(), a2.begin() + i, b[i] - i) - a2.begin()) - 1;
        if (a2[j] != b[i] - i) {
          r = -1;
          break;
        }
        r += i - j;
      }
    } else if (a[i] < b[i]) {
      // ->
      if (b[i] == b[i + 1] - 1) {
        r++;
      } else {
        int j = lower_bound(a2.begin() + (i + 1), a2.end(), b[i] - i) - a2.begin();
        if (a2[j] != b[i] - i) {
          r = -1;
          break;
        }
        r += j - i;
      }
    }
  }
  cout << r << endl;
}
