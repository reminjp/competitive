#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  set<int> s1, s2, s3;
  for (auto c : s) {
    int i = c - '0';
    for (auto e2 : s2) s3.insert(10 * e2 + i);
    for (auto e1 : s1) s2.insert(10 * e1 + i);
    s1.insert(i);
  }
  cout << s3.size() << endl;
}
