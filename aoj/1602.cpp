#include <bits/stdc++.h>
using namespace std;

int main() {
  static auto add = [](int a, int b) { return a + b; };
  static auto mul = [](int a, int b) { return a * b; };
  int n;
  while (cin >> n, n) {
    vector<string> a(n);
    for (auto& e : a) {
      cin >> e;
    }
    a.push_back("0");
    vector<pair<function<int(int, int)>, int>> v{make_pair(add, 0)};
    for (auto e : a) {
      while (e.size() - 1 < v.size() - 1) {
        (v.rbegin() + 1)->second = (v.rbegin() + 1)->first((v.rbegin() + 1)->second, v.rbegin()->second);
        v.pop_back();
      }
      char c = *e.rbegin();
      if (c == '+') {
        v.push_back(make_pair(add, 0));
      } else if (c == '*') {
        v.push_back(make_pair(mul, 1));
      } else {
        v.rbegin()->second = v.rbegin()->first(v.rbegin()->second, c - '0');
      }
    }
    cout << v.back().second << endl;
  }
}
