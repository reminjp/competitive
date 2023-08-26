#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] == a[0] + i) continue;
    cout << a[0] + i << endl;
    break;
  }
}
