#include <bits/stdc++.h>
using namespace std;

bool f(string a) {
  int s = 0;
  for (int i = 0; i < a.size() - 1; i++) s += (a[i] - '0') * (2 + i);
  return s % 11 % 10 == a.back() - '0';
}

int main() {
  int n;
  cin >> n;
  for (; n > 0; n--) {
    string y, x, a;
    cin >> y >> x;
    a = y + x;
    cout << (f(a) ? "YES" : "NO") << endl;
  }
}
