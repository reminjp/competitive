#include <bits/stdc++.h>
using namespace std;

vector<int> square;
int n;

int f(int s, int b, int i) {
  int r = s == n;
  if (i < 4 && s + square[b] <= n) {
    for (int j = b; j < square.size(); j++) {
      r += f(s + square[j], j, i + 1);
    }
  }
  return r;
}

int main() {
  for (int i = 1; i * i < 1 << 15; i++) {
    square.push_back(i * i);
  }
  while (cin >> n, n) {
    cout << f(0, 0, 0) << endl;
  }
}
