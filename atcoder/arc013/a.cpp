#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3), b(3);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  sort(begin(b), end(b));
  int m = 0;
  do {
    int t = 1;
    for (int i = 0; i < 3; i++) t *= a[i] / b[i];
    m = max(m, t);
  } while (next_permutation(begin(b), end(b)));
  cout << m << endl;
  return 0;
}
