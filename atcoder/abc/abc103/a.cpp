#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3);
  for (auto &e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  cout << a.back() - a.front() << endl;
}
