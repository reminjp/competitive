#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, const regex& separator) {
  vector<string> r;
  auto it = sregex_token_iterator(begin(s), end(s), separator, -1);
  auto it_end = sregex_token_iterator();
  while (it != it_end) r.push_back(*it++);
  return r;
}

int main() {
  string s1, s2;
  while (cin >> s1, s1 != ".") {
    cin >> s2;
    string r = "DIFFERENT";
    auto t1 = split(s1, regex("\""));
    auto t2 = split(s2, regex("\""));
    if (t1.size() == t2.size()) {
      int d = 0;
      for (int i = 0; i < t1.size(); i++) {
        d += (!(i % 2) + 1) * (t1[i] != t2[i]);
      }
      if (d == 0) {
        r = "IDENTICAL";
      } else if (d == 1) {
        r = "CLOSE";
      }
    }
    cout << r << endl;
  }
}
