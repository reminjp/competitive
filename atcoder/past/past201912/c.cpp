#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(6);
  for (auto& e : a) cin >> e;
  sort(a.rbegin(), a.rend());
  cout << a[3 - 1] << endl;
}
