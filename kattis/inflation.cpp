#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  bool e = false;
  double f = 1;
  for (int i = 0; i < n; i++) {
    e |= a[i] > i + 1;
    f = min(f, (double)a[i] / (i + 1));
  }
  if (e) {
    cout << "impossible" << endl;
  } else {
    cout << fixed << setprecision(6) << f << endl;
  }
}
