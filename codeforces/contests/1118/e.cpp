#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if ((long long)k * (k - 1) < n) {
    cout << "NO" << endl;
    return 0;
  }

  vector<pair<int, int>> r;
  for (int i = 0; i < k - 1 && r.size() < n; i++) {
    for (int j = 0; j < k && r.size() < n; j++) {
      r.push_back({j + 1, (i + j + 1) % k + 1});
    }
  }
  cout << "YES" << endl;
  for (auto e : r) {
    cout << e.first << " " << e.second << endl;
  }
}
