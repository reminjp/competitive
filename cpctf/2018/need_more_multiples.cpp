#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  int k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cout << n;
    for (int j = 0; j < i; j++) {
      cout << "0";
    }
    cout << endl;
  }
  return 0;
}
