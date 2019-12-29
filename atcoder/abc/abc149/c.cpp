#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  vector<bool> p(2 * x + 1, true);
  for (int i = 2; i < p.size(); i++) {
    if (!p[i]) continue;
    for (int j = 2 * i; j < p.size(); j += i) p[j] = false;
  }
  int r = x;
  while (r < p.size() && !p[r]) r++;
  cout << r << endl;
}
