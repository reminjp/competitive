#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string r;
  stack<int> h;
  for (auto e : s) {
    if (e == '(') {
      h.push(r.size());
    } else if (e == ')') {
      auto t = r.substr(h.top());
      reverse(t.begin(), t.end());
      r.append(t);
      h.pop();
    } else {
      r.push_back(e);
    }
  }
  cout << r << endl;
}
