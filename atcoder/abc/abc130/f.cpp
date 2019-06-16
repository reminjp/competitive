#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

struct range {
  double bot = 1e9, top = -1e9;
  void insert(double x) {
    bot = min(bot, x);
    top = max(top, x);
  }
};

int main() {
  int n;
  cin >> n;
  range x_dec, x_stop, x_inc, y_dec, y_stop, y_inc;
  for (int i = 0; i < n; i++) {
    int x, y;
    string d;
    cin >> x >> y >> d;
    switch (d.front()) {
      case 'R': {
        x_inc.insert(x);
        y_stop.insert(y);
        break;
      }
      case 'L': {
        x_dec.insert(x);
        y_stop.insert(y);
        break;
      }
      case 'U': {
        x_stop.insert(x);
        y_inc.insert(y);
        break;
      }
      case 'D': {
        x_stop.insert(x);
        y_dec.insert(y);
        break;
      }
    }
  }

  double r = 1e18;
  for (ll i = 0; i <= 4e8; i++) {
    double t = i / 2.0;
    double w = max({x_dec.top - t, x_stop.top, x_inc.top + t}) - min({x_dec.bot - t, x_stop.bot, x_inc.bot + t});
    double h = max({y_dec.top - t, y_stop.top, y_inc.top + t}) - min({y_dec.bot - t, y_stop.bot, y_inc.bot + t});
    r = min(r, w * h);
  }
  cout << fixed << setprecision(9);
  cout << r << endl;
}
