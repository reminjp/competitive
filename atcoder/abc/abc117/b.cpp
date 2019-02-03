#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  int s = 0;
  for (auto &e : l) {
    cin >> e;
    s += e;
  }
  bool r = true;
  for (auto e : l) {
    r &= e < s - e;
  }
  cout << (r ? "Yes" : "No") << endl;
}
