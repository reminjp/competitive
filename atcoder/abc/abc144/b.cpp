#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = false;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      r |= i * j == n;
    }
  }
  cout << (r ? "Yes" : "No") << endl;
}
