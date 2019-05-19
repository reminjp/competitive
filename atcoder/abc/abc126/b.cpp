#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 10 * (s[0] - '0') + (s[1] - '0'), b = 10 * (s[2] - '0') + (s[3] - '0');
  if (1 <= a && a <= 12 && 1 <= b && b <= 12) {
    cout << "AMBIGUOUS" << endl;
  } else if (1 <= a && a <= 12) {
    cout << "MMYY" << endl;
  } else if (1 <= b && b <= 12) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
}
