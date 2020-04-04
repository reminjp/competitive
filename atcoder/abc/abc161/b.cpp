#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int s = 0;
  for (auto& e : a) {
    cin >> e;
    s += e;
  }
  sort(a.rbegin(), a.rend());
  cout << (a[m - 1] * 4 * m >= s ? "Yes" : "No") << endl;
}
