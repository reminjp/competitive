#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 100000;
  vector<bool> p(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (p[i]) {
      for (int j = 2 * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    if (p[i]) v.push_back(i);
  }

  int m, a, b;
  while (cin >> m >> a >> b, m) {
    int p = 0, q = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = i; j < v.size() && (long long)v[i] * v[j] <= (long long)m && a * v[j] <= b * v[i]; j++) {
        if (v[i] * v[j] > v[p] * v[q]) {
          p = i;
          q = j;
        }
      }
    }
    cout << v[p] << " " << v[q] << endl;
  }
}
