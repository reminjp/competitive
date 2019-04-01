#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<string, string>> a(n);
  for (auto &e : a) {
    cin >> e.first >> e.second;
  }
  sort(begin(a), end(a));
  for (auto e : a) {
    cout << e.first << " " << e.second << endl;
  }
}
