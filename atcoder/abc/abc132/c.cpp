#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto& e : d) cin >> e;
  sort(begin(d), end(d));
  cout << d[n / 2] - d[n / 2 - 1] << endl;
}
