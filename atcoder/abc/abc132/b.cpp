#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto& e : p) cin >> e;
  int r = 0;
  for (int i = 1; i < n - 1; i++) r += p[i - 1] < p[i] && p[i] < p[i + 1] || p[i + 1] < p[i] && p[i] < p[i - 1];
  cout << r << endl;
}
