#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < days.size(); j++) {
      if (s == days[j]) {
        cout << days[(j + 1) % days.size()] << endl;
      }
    }
  }
}
