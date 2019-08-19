#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &e : p) cin >> e;
  auto m = max_element(begin(p), end(p));
  int r = 0;
  for (auto i = begin(p); i != end(p); i++) r += i == m ? *i / 2 : *i;
  cout << r << endl;
}
