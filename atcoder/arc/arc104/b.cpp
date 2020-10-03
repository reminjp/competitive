#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> a(n + 1), t(n + 1), c(n + 1), g(n + 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i] + (s[i] == 'A' ? 1 : 0);
    t[i + 1] = t[i] + (s[i] == 'T' ? 1 : 0);
    c[i + 1] = c[i] + (s[i] == 'C' ? 1 : 0);
    g[i + 1] = g[i] + (s[i] == 'G' ? 1 : 0);
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j] - a[i] == t[j] - t[i] && c[j] - c[i] == g[j] - g[i]) r++;
    }
  }
  cout << r << endl;
}
