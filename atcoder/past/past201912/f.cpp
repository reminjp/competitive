#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  vector<string> r;
  string t;
  int c = 0;
  for (const auto& e : s) {
    t.push_back(e);
    if ('A' <= e && e <= 'Z') {
      c++;
      if (c == 2) {
        t.front() = t.front() - 'A' + 'a';
        t.back() = t.back() - 'A' + 'a';
        r.push_back(t);
        t.clear();
        c = 0;
      }
    }
  }
  sort(r.begin(), r.end());

  for (auto& e : r) {
    e.front() = e.front() - 'a' + 'A';
    e.back() = e.back() - 'a' + 'A';
    cout << e;
  }
  cout << endl;
}
