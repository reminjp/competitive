#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  while (k--) {
    int d;
    cin >> d;
    while (d--) {
      int a;
      cin >> a;
      s.insert(a);
    }
  }
  cout << n - s.size() << endl;
}
