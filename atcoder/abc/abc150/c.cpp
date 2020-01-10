#include <bits/stdc++.h>
using namespace std;

bool is_equal(const vector<int>& a, const vector<int>& b) {
  bool r = true;
  for (int i = 0; i < a.size(); i++) r = r && a[i] == b[i];
  return r;
}

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n), v(n);
  for (auto& e : p) cin >> e;
  for (auto& e : q) cin >> e;
  iota(v.begin(), v.end(), 1);
  int a, b, i = 0;
  do {
    if (is_equal(v, p)) a = i;
    if (is_equal(v, q)) b = i;
    i++;
  } while (next_permutation(v.begin(), v.end()));
  cout << abs(a - b) << endl;
}
