#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> s;
  for (int i = 0; i <= (int)2e5; i++) s.insert(i);

  while (n--) {
    int p;
    cin >> p;
    s.erase(p);
    cout << *s.begin() << endl;
  }
}
