#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  cout << (n - 2) / (k - 1) + 1 << endl;
}
