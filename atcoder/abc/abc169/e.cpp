#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (n % 2) {
    cout << b[n / 2] - a[n / 2] + 1 << endl;
  } else {
    cout << (b[n / 2 - 1] + b[n / 2]) - (a[n / 2 - 1] + a[n / 2]) + 1 << endl;
  }
}
