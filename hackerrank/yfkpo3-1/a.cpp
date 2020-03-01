#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<string> s(a), t(b), u(c);
  for (auto& e : s) cin >> e;
  for (auto& e : t) cin >> e;
  for (auto& e : u) cin >> e;
  set<string> r;
  for (const auto& e : u) r.insert(e);
  for (const auto& e : s) r.erase(e);
  for (const auto& e : t) r.erase(e);
  cout << r.size() << endl;
}
