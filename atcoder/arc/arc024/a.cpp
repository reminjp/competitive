#include <bits/stdc++.h>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;
  map<int, int> l, r;
  for (int i = 0; i < L; i++) {
    int x;
    cin >> x;
    l[x]++;
  }
  for (int i = 0; i < R; i++) {
    int x;
    cin >> x;
    r[x]++;
  }
  int s = 0;
  for (auto e : l) {
    s += min(e.second, r[e.first]);
  }
  cout << s << endl;
}
