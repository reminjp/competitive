#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = 0;
  for (auto e : s) {
    n += e == '1';
  }
  cout << n << endl;
  return 0;
}
