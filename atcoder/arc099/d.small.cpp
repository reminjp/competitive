#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 1e6;
  vector<double> u(n);
  for (int i = 1; i < n; i++) {
    bool b = true;
    int s = 0;
    for (int j = 1; j <= i; j *= 10) {
      int d = i % (10 * j) / j;
      s += d;
    }
    u[i] = (double)i / s;
  }

  vector<int> v;
  for (int i = 1; i < n; i++) {
    bool b = true;
    for (int j = i + 1; j < n; j++) {
      if (u[i] > u[j]) {
        b = false;
        break;
      }
    }
    if (b) {
      v.push_back(i);
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cout << v[i] << endl;
  }
}
