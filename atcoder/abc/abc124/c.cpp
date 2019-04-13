#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> r(2);
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < 2; j++) {
      r[j] += (s[i] - '0' + j) % 2 == i % 2;
    }
  }
  cout << min(r[0], r[1]) << endl;
}
