#include <bits/stdc++.h>
using namespace std;

const int MIN = -(int)1e9;
const int MAX = (int)1e9;
const int X = MAX + 1;

int main() {
  int n;
  while (cin >> n, n) {
    vector<int> a(n + 2);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      a[i + 1] = s.front() == 'x' ? X : stoi(s);
    }
    a[0] = MAX + 3;
    a[n + 1] = (n + 1) % 2 ? MIN - 3 : MAX + 3;
    int bot = MIN - 2, top = MAX + 3;
    for (int i = 0; i < n; i++) {
      if (a[i + 1] == X) {
        if (a[i + 2] == X) {
          bot = top;
        } else {
          if ((i + 1) % 2) {
            top = min(top, min(a[i], a[i + 2]));
          } else {
            bot = max(bot, max(a[i], a[i + 2]) + 1);
          }
        }
      } else {
        if (a[i + 2] != X) {
          if ((i + 1) % 2) {
            if (a[i + 1] >= a[i + 2]) {
              bot = top;
            }
          } else {
            if (a[i + 1] <= a[i + 2]) {
              bot = top;
            }
          }
        }
      }
    }
    if (top - bot == 1) {
      cout << bot << endl;
    } else {
      cout << (top - bot > 1 ? "ambiguous" : "none") << endl;
    }
  }
}
