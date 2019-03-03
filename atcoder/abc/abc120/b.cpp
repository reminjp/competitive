#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> r;
  for (int i = 1; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      r.push_back(i);
    }
  }
  cout << r[r.size() - k] << endl;
}
