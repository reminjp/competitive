#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  int s = 0;
  for (auto e : n) s += e - '0';
  cout << (s % 9 == 0 ? "Yes" : "No") << endl;
}
