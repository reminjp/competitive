#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto& e : d) cin >> e;
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) r += d[i] * d[j];
  }
  cout << r << endl;
}
