#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int s = 0;
  while (m--) {
    int e;
    cin >> e;
    s += e;
  }
  cout << (s <= n ? n - s : -1) << endl;
}
