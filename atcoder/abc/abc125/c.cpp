#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct gcd_segment_tree {
 private:
  int n;
  vector<int> node;

 public:
  gcd_segment_tree(const vector<int>& v) {
    n = 1;
    while (n < v.size()) n *= 2;
    node.resize(2 * n - 1);
    for (int i = 0; i < v.size(); i++) node[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) node[i] = gcd(node[2 * i + 1], node[2 * i + 2]);
  }

  int get(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return node[k];
    int vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
    return gcd(vl, vr);
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  gcd_segment_tree s(a);
  int r = 0;
  for (int i = 0; i < n; i++) r = max(r, gcd(s.get(0, i), s.get(i + 1, n)));
  cout << r << endl;
}
