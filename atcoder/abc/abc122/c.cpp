#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> a(n + 1);
  for (int i = 0; i < n - 1; i++) {
    a[i + 1] = s[i] == 'A' && s[i + 1] == 'C';
  }
  for (int i = 0; i < n; i++) {
    a[i + 1] += a[i];
  }
  for (; q > 0; q--) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l - 1] - (r < n && s[r - 1] == 'A' && s[r] == 'C') << endl;
  }
}
