#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, char> m = {{'O', '0'}, {'D', '0'}, {'I', '1'}, {'Z', '2'}, {'S', '5'}, {'B', '8'}};
  for (auto &e : s) {
    if (m.count(e)) {
      e = m[e];
    }
  }
  cout << s << endl;
}
