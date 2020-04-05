#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<bool, int>> r(n);
  for (auto& e : r) {
    char c;
    cin >> e.second >> c;
    e.first = c == 'B';
  }
  sort(r.begin(), r.end());
  for (auto e : r) cout << e.second << '\n';
  cout << flush;
}
