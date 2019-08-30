#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<string, string>> v(n);
  for (auto& e : v) {
    cin >> e.second;
    e.first = e.second;
    reverse(begin(e.first), end(e.first));
  }
  sort(begin(v), end(v));
  for (const auto& e : v) {
    cout << e.second << endl;
  }
}
