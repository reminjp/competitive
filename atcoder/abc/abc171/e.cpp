#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  for (auto& e : a) {
    cin >> e;
    s ^= e;
  }

  for (auto& e : a) cout << (s ^ e) << ' ';
  cout << endl;
}
