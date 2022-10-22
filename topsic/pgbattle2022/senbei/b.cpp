#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3 * n);
  for (auto& e : a) cin >> e;

  auto v = a;
  sort(v.begin(), v.end());
  set<int> s;
  for (int i = n; i < 2 * n; i++) s.insert(v[i]);

  for (int i = 0; i < 3 * n; i++) {
    if (s.count(a[i])) cout << i + 1 << endl;
  }
}
