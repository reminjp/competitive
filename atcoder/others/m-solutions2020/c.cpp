#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  for (int i = k; i < n; i++) cout << (a[i - k] < a[i] ? "Yes" : "No") << endl;
}
