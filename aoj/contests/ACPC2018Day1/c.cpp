#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r;
  if (n < 3) {
    r = 0;
  } else {
    vector<bool> p(n + 3, true);
    p[0] = p[1] = false;
    for (int i = 2; i < p.size(); i++) {
      if (p[i]) {
        for (int j = i + i; j < p.size(); j += i) {
          p[j] = false;
        }
      }
    }
    r = 0;
    for (int i = 3; i <= n + 2; i++) {
      r += 2 * (p[i] && p[i - 2]);
    }
  }
  cout << r << endl;
}
