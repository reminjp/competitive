#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;
vector<double> x, y;

void dfs_x(int current, int parent) {
  static int k = 0;
  int i = 0;
  for (; i < v[current].size() / 2; i++) {
    if (v[current][i] != parent) dfs_x(v[current][i], current);
  }
  x[current] = -0.5 + 1.0 * k / (n - 1);
  k++;
  for (; i < v[current].size(); i++) {
    if (v[current][i] != parent) dfs_x(v[current][i], current);
  }
}

void dfs_y(int current, int parent) {
  for (auto e : v[current]) {
    if (e == parent) continue;
    y[e] = y[current] + sqrt(1.0 - pow(x[e] - x[current], 2.0));
    dfs_y(e, current);
  }
}

int main(void) {
  cin >> n;
  v = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }
  y = vector<double>(n);
  x = vector<double>(n);
  dfs_x(0, 0);
  dfs_y(0, 0);
  cout << fixed << setprecision(9);
  for (int i = 0; i < n; i++) {
    cout << x[i] << " " << y[i] << endl;
  }
}
