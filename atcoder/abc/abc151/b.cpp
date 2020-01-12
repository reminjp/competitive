#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int r = n * m;
  for (int i = 0; i < n - 1; i++) {
    int e;
    cin >> e;
    r -= e;
  }
  cout << (r > k ? -1 : max(0, r)) << endl;
}
