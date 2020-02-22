#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto& e : x) cin >> e;

  int r = 1e9;
  for (int i = 1; i <= 100; i++) {
    int s = 0;
    for (auto e : x) s += pow(e - i, 2);
    r = min(r, s);
  }
  cout << r << endl;
}
