#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = false;
  for (; n > 0; n--) {
    string a, b;
    cin >> a >> b;
    int i = 0;
    for (auto e : a) {
      if (e == b[i]) i++;
      if (i >= b.size()) break;
    }
    r = r || i == b.size();
  }
  cout << (r ? "YES" : "NO") << endl;
}
