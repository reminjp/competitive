#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, x;
  cin >> k >> x;
  string s, t;
  if (x <= k) {
    while (s.size() < x) s.push_back('0');
    while (s.size() < k) s.push_back('1');
    while (t.size() < x) t.push_back('9');
    while (t.size() < k) t.push_back('7');
  } else if (x <= 2 * k) {
    while (s.size() < 2 * k - x) s.push_back('0');
    while (s.size() < k) s.push_back('8');
    while (t.size() < 2 * k - x) t.push_back('9');
    while (t.size() < k) t.push_back('8');
  } else {
    s = t = "-1";
  }
  cout << s << endl << t << endl;
  return 0;
}
