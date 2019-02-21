#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n + 1), s(n + 1), e(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    s[i + 1] = s[i] + a[i + 1];
    e[i + 1] = e[i] + ((n - i) % 2 ? a[i + 1] : 0);
  }
  for (; q > 0; q--) {
    int x;
    cin >> x;
    int ok = 0, ng = 1e9;
    int head, tail, first, second;
    while (true) {
      int w = (ok + ng) / 2;
      head = lower_bound(begin(a) + 1, end(a), x - w) - begin(a);
      tail = lower_bound(begin(a) + 1, end(a), x + w) - begin(a);
      first = n + 1 - tail;
      second = tail - head;
      if (!(ok + 1 < ng)) {
        break;
      }
      if (second + 1 <= first) {
        ok = w;
      } else if (second + 1 > first) {
        ng = w;
      }
    }
    if (second + 1 < first) {
      tail++;
    }
    cout << (s[n] - s[tail - 1]) + e[head - 1] << endl;
  }
}
