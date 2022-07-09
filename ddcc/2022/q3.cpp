#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int T = 3;
  while (T--) {
    ll cost_a, cost_b;
    int hp, boss_hp, atk;
    cin >> cost_a >> cost_b >> hp >> boss_hp >> atk;
    vector<int> boss_atk(99);
    for (auto& e : boss_atk) cin >> e;
    boss_atk.push_back(INF);

    vector dp(101, vector(hp + 1, vector<ll>(boss_hp + 1, INF)));
    dp[0][hp][boss_hp] = 0;
    for (int t = 0; t < 100; t++) {
      for (int i = 1; i <= hp; i++) {
        for (int j = 0; j <= boss_hp; j++) {
          int i2 = max(1, i - boss_atk[t]);
          int hp_shortage = max(0, 1 - (i - boss_atk[t]));
          {
            int j2 = max(0, j - atk);
            set_if_less(dp[t + 1][i2][j2], dp[t][i][j] + (j2 == 0 ? 0 : hp_shortage * cost_b));
          }
          {
            int j2 = max(0, j - 2 * atk);
            set_if_less(dp[t + 1][i2][j2], dp[t][i][j] + cost_a + (j2 == 0 ? 0 : hp_shortage * cost_b));
          }
        }
      }
    }

    ll r = INF;
    for (int t = 1; t <= 100; t++) {
      for (int i = 1; i <= hp; i++) r = min(r, dp[t][i][0]);
    }

    cout << (r == INF ? -1 : r);
    if (T) cout << ',';
  }
  cout << endl;
}
