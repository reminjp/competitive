#include <bits/stdc++.h>
using namespace std;

int main() {
  regex r(R"(^.*okyo.*ech.*$)");
  int n;
  cin >> n;
  for (; n > 0; n--) {
    string s;
    cin >> s;
    cout << (regex_match(s, r) ? "Yes" : "No") << endl;
  }
}
