#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> day{"Sunday",   "Monday", "Tuesday", "Wednesday",
                     "Thursday", "Friday", "Saturday"};
  string s;
  cin >> s;
  int n = find(begin(day), end(day), s) - begin(day);
  cout << (6 - n) % 6 << endl;
  return 0;
}
