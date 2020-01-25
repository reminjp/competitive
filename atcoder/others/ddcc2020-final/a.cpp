#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  int s = 0;
  for (auto e : a) {
    int c = 0;
    for (int i = 2; i <= e; i++) {
      while (e % i == 0) {
        e /= i;
        c++;
      }
    }
    s ^= c;
  }
  cout << (s ? "Yes" : "No") << endl;
}
