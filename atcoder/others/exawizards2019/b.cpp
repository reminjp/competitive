#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int r = 0;
  for (auto e : s) {
    r += e == 'R';
  }
  cout << (r > n - r ? "Yes" : "No") << endl;
}
