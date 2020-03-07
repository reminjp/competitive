#include <bits/stdc++.h>
using namespace std;

using Dice = array<int, 6>;

int main() {
  int N, M;
  cin >> N >> M;

  int x = 0;
  Dice dice{1, 2, 3, 4, 5, 6};
  vector<int> a(N + 1, -1), c(N + 1);
  // a[N] = 5000;
  // a[0] = a[N - 5] = a[N - 4] = a[N - 3] = a[N - 2] = a[N - 1] = 0;

  Dice dice2{6, 6, 6, 6, 6, 5};

  while (M--) {
    int k = 0;
    while (k < 6 && dice[k] == dice2[k]) k++;
    if (k < 5) {
      dice[k] = dice2[k];
    } else {
      dice[5] = (N - x) % 6 == 0 ? 6 : 5;
    }

    for (auto e : dice) cout << e << ' ';
    cout << endl;

    int d, v;
    cin >> d >> v >> x;
    a[x] = v;
    c[x]++;

    // cerr << d << ' ' << v << ' ' << x << '\n';
  }

  // for (auto e : a) cerr << e << ' ';
  // cerr << endl;

  // for (int i = 0; i < N + 1; i++) cerr << a[i] << 'x' << c[i] << ' ';
  // cerr << endl;
}
