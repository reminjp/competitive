#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    b[a - 1]++;
  }

  int a0 = 0, a2 = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) a0 = i + 1;
    if (b[i] == 2) a2 = i + 1;
  }

  if (a0 == a2) {
    cout << "Correct" << endl;
  } else {
    cout << a2 << ' ' << a0 << endl;
  }
}
