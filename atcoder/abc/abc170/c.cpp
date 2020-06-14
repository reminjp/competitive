#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  set<int> s;
  while (n--) {
    int e;
    cin >> e;
    s.insert(e);
  }
  int r = 1e9;
  for (int i = 0; i <= 101; i++) {
    if (s.count(i)) continue;
    if (abs(i - x) < abs(r - x)) r = i;
  }
  cout << r << endl;
}
