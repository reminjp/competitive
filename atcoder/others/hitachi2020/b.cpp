#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  int r = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  while (M--) {
    int x, y, c;
    cin >> x >> y >> c;
    r = min(r, a[x - 1] + b[y - 1] - c);
  }
  cout << r << endl;
}
